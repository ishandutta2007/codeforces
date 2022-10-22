#include <bits/stdc++.h>

using namespace std;

int x[10005], y[10005];

int solve(vector<int> a, int b){
	vector<int> c(30);
	for(int i=0; i < a.size(); ++i)
		for(int j=0; j < 30; ++j)
			if(a[i] & (1<<j))
				c[j] += (1<<i);
	for(int j=0; j < 30; ++j)
		if(b & (1<<j))
			c[j] += (1<<a.size());
	for(int j=0; j <= a.size(); ++j){
		for(int i=0; i < c.size(); ++i){
			if((c[i]&(1<<j)) && (c[i]%(1<<j) == 0)){
				if(j == a.size())
					return -1;
				for(int k=0; k < c.size(); ++k){
					if(i != k && (c[k]&(1<<j))){
						c[k]^=c[i];
					}
				}
				break;
			}
		}
	}
	int ans=0;
	for(int i=0; i < c.size(); ++i)
		if(c[i]&(1<<a.size()))
			for(int j=0; j < a.size(); ++j)
				if(c[i]&(1<<j))
					ans += (1<<j);
	return ans;
}

vector<int> independent;

vector<int> getSet(vector<int> v){
	vector<int> ans;
	for(int i=0; i < v.size(); ++i)
		ans.push_back(x[v[i]]);
	return ans;
}

vector<pair<int, int> > ans;

void print(int ind, int res){
	for(int i=0; i < 31; ++i){
		if(res&(1<<i)){
			//printf("%d %d\n", ind+1, independent[i]+1);
			ans.push_back(make_pair(ind, independent[i]));
			x[ind]^=x[independent[i]];
		}
	}
}

int perform(int ind, int other){
	ind=independent[ind];
	other=independent[other];
	ans.push_back(make_pair(ind, other));
	//printf("%d %d\n", ind+1, other+1);
	x[ind]^=x[other];
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=0; i < n; ++i)
		scanf("%d", x+i);
	for(int i=0; i < n; ++i)
		scanf("%d", y+i);
	for(int i=0; i < n; ++i){
		int res=solve(getSet(independent), x[i]);
		if(res == -1)
			independent.push_back(i);
		else{
			
			ans.push_back(make_pair(i, i));
			x[i]=0;
		}
	}
	for(int i=0; i < n; ++i){
		int res=solve(getSet(independent), y[i]);
		if(res == -1){
			puts("-1");
			return 0;
		}
		if(x[i] == 0)print(i, res);	
	}

	while(true){
		vector<int> v;
		while(true){
			bool any=0;
			v.clear();
			for(int i=0; i < independent.size(); ++i){
				int I=independent[i];
				if(x[I] == y[I])
					continue;
				int res=solve(getSet(independent), y[I]);
				if(res&(1<<i)){
					any=1;
					for(int j=0; j < independent.size(); ++j)
						if(j != i && (res&(1<<j)))
							perform(i, j);
					//assert(x[I] == y[I]);
				}
				else
					v.push_back(i);
			}
			if(!any)
				break;
		}
		bool any=0;
		for(int j=0; j < v.size(); ++j){
			int i=v[j];
			int I=independent[i];
			int res=solve(getSet(independent), y[I]);
			if(res&(1<<i)){
				puts("ERROR!");
				return 0;
			}
			for(int k=0; k < v.size(); ++k){
				if(res&(1<<v[k])){
					perform(v[k], v[j]);
					any=1;
					assert(solve(getSet(independent), y[I])&(1<<i));
					break;
				}
			}
			if(any)
				break;
		}
		if(!any)
			break;
	}
	vector<int> nInd;
	for(int i=0; i < independent.size(); ++i){
		int I=independent[i];
		if(x[I] == y[I])
			nInd.push_back(I);
		else{
			ans.push_back(make_pair(I, I));
			x[I]=0;
		}
	}
	vector<int> old=independent;
	independent = nInd;
	for(int i=0; i < old.size(); ++i){
		if(x[old[i]] == y[old[i]])
			continue;
		int res=solve(getSet(independent), y[old[i]]);
		if(res == -1){
			puts("Weird");
			return 0;
		}
		for(int j=0; j < independent.size(); ++j){
			if(res&(1<<j)){
				ans.push_back(make_pair(old[i], independent[j]));
				x[old[i]]^=x[independent[j]];
			}
		}
		if(x[old[i]] != y[old[i]]){
			puts("Strange");
			return 0;
		}
	}
	for(int i=0; i < n; ++i)
		assert(x[i] == y[i]);
	printf("%d\n", ans.size());
	for(int i=0; i < ans.size(); ++i)
		printf("%d %d\n", ans[i].first+1, ans[i].second+1);
}