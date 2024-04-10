#include <bits/stdc++.h>

using namespace std;
int n, m;
int s[35][35];
int t[35][35];
vector<pair<int, int> > ans;
vector<pair<int, int> > reverseList;
int x, y;

void performMove(int i, int j){
	swap(s[i][j], s[x][y]);
	x=i;
	y=j;
	ans.push_back(make_pair(x,y));
}

bool check(){
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			if(s[i][j] != t[i][j])
				return 0;
	return 1;
}
bool mirror=0;

void printAns(){
	assert(ans.size() < 1000000);
	printf("%d\n", ans.size()-1);
	for(int i=0; i < ans.size(); ++i){
		if(mirror)
			printf("%d %d\n", ans[i].second+1, ans[i].first+1);
		else
			printf("%d %d\n", ans[i].first+1, ans[i].second+1);
	}
}

void reverse(int i, int j){
	reverseList.push_back(make_pair(x, y));
	performMove(i, j);
}

void transpos(int i1, int j1, int i2, int j2){
	reverseList.clear();
	if(i1 == i2){
		if(i1 == n-1){
			reverse(x-1, y);
			while(y > j1)
				reverse(x, y-1);
		}
		else{
			while(y > j1)
				reverse(x, y-1);
			while(x > i1+1)
				reverse(x-1, y);
		/*for(int k=n-2; k > i1; --k)
			reverse(k, m-1);
		for(int k=m-2; k > j1; --k)
			reverse(i1+1, k);*/
		}
	}
	else{
		if(j1 == m-1){
			reverse(x, y-1);
		}
		else{
			while(y > j1+1){
				reverse(x, y-1);
			}
		}
		while(x > i1)
			reverse(x-1, y);
	}
	int backx=x, backy=y;
	performMove(i1,j1);
       	performMove(i2,j2);
	performMove(backx, backy);
	for(int i=reverseList.size()-1; i >= 0; --i)
		performMove(reverseList[i].first, reverseList[i].second);	
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			scanf("%d", s[i]+j);
	for(int i=0; i < n; ++i)
		for(int j=0; j < m; ++j)
			scanf("%d", t[i]+j);
	if(n == 1){
		mirror=1;
		for(int i=0; i < m; ++i){
			s[i][0]=s[0][i];
			t[i][0]=t[0][i];
		}
		n=m;
		m=1;
	}
	if(m == 1){
		int ssaved[35][35];
				for(int k=0; k < n; ++k)
					for(int q=0; q < m; ++q)
						ssaved[k][q]=s[k][q];
		for(int i=0; i < n; ++i){
			for(int j=0; j < n; ++j){
				for(int k=0; k < n; ++k)
					for(int q=0; q < m; ++q)
						s[k][q]=ssaved[k][q];
				ans.clear();
				x=i;
				y=0;
				ans.push_back(make_pair(x,y));
				int k=i;
				while(k != j){
					if(k > j)
						--k;
					else
						++k;
					performMove(k,0); 
				}
				if(check()){
					printAns();
					return 0;
				}
			}
		}
		puts("-1");
		return 0;
	}
	for(int i=0; i <= n; ++i){
		if(i == n){
			puts("-1");
			return 0;
		}
		for(int j=0; j < m; ++j){
			if(s[i][j] == t[n-1][m-1]){
				x=i;
				y=j;
				ans.push_back(make_pair(x, y));
				while(x < n-1)
					performMove(x+1, y);
				while(y < m-1)
					performMove(x, y+1);	

				i=n;
				break;
			}
		}
		if(i==n)
		break;
	}
	while(!check()){
		for(int i=0; i < n; ++i)
			for(int j=0; j < m; ++j){
				if(s[i][j] != t[i][j]){
					int k=i, l=j;
					while(k < n){
						++l;
						if(l == m){
							l=0;
							++k;
						}
						if(k == n-1 && l == m-1){
							puts("-1");
							return 0;
						}
						if(s[k][l] == t[i][j]){
							break;
						}
					}
					while(l != j){
						int lnew;
						if(l > j)
							lnew=l-1;
						else
							lnew=l+1;
						if(lnew == m-1 && k == n-1){
							performMove(n-1, m-2);
							performMove(n-2, m-1);
							performMove(n-1, m-1);
							--k;
						}
						else
							transpos(k, l, k, lnew);
						l=lnew;
					}
					while(k != i){
						transpos(k-1, l, k, l);
						--k;
					}
				}
			}
	}
	printAns();
}