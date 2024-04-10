#include<cstdio>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

set<pair<int, int> > st;
map<pair<int, int>, int> mp;
vector<pair<int, int> > a;
set<int> q;

bool has(int x, int y){
	return st.find(make_pair(x, y)) != st.end();
}

int cnt(int x, int y){
	int ans = 0;
	if (!has(x, y)) return 0;
	if (has(x-1, y-1)) ans ++;
	if (has(x, y-1)) ans ++;
	if (has(x+1, y-1)) ans ++;
	return ans;
}

bool hasUp(pair<int, int> p){
	int x = p.first, y = p.second;
	return cnt(x-1, y+1) == 1 || cnt(x, y+1) == 1 || cnt(x+1, y+1) == 1;
}

void update(int x, int y){
	pair<int, int> p = make_pair(x, y);
	if (!has(x, y)) return;
	if (!hasUp(p)){
		 q.insert(mp[p]);
	}
}
int main(){
	int n;
	cin >> n;
	for (int i=0; i<n; ++i){
		int x, y;
		cin >> x >> y;
		pair<int, int> p = make_pair(x, y);
		a.push_back(p);
		mp[p] = i;
		st.insert(p);
	}
	for (int i=0; i<n; ++i){
		if(!hasUp(a[i])){
			 q.insert(i);
		}
	}
	long long P = 1000000009, ans = 0;
	for (int i=0; i<n; ++i){
		int c = 0;
		if (i % 2 == 0){
			c = *(q.rbegin());
		}else{
			c = *(q.begin());
		}
		q.erase(c);
		ans = ans * n + c;
		ans = ans % P;
		st.erase(a[c]);
		int x = a[c].first, y = a[c].second;
		update(x-1, y-1);
		update(x, y-1);
		update(x+1, y-1);
		for (int j=x-2; j<=x+2; ++j){
			if (has(j, y) && hasUp(make_pair(j, y))) q.erase(mp[make_pair(j, y)]);
		}
	}
	printf("%d\n", (int) ans);
	return 0;
}