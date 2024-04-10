#include <bits/stdc++.h>
#define MAXN 100005
using namespace std;

int n;
int m;
vector<pair<pair<int, int>, int> > parts;
vector<pair<pair<pair<int, int>, int>, int> > actors;
set<pair<pair<int, int>, int> > S;
int ans[MAXN];

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		parts.push_back(make_pair(make_pair(a, b), i));
	}
	scanf("%d", &m);
	for(int i=0; i < m; ++i){
		int c, d, k;
		scanf("%d%d%d", &c, &d, &k);
		actors.push_back(make_pair(make_pair(make_pair(c, d), k), i));
	}
	sort(parts.begin(), parts.end());
	sort(actors.begin(), actors.end());
	int j=0;
	for(int i=0; i < parts.size(); ++i){
		while(j < actors.size() && actors[j].first.first.first <= parts[i].first.first){
			S.insert(make_pair(make_pair(actors[j].first.first.second, actors[j].first.second), actors[j].second));
			++j;
		}
		auto it=S.lower_bound(make_pair(make_pair(parts[i].first.second, -1), 0));
		if(it == S.end()){
			puts("NO");
			return 0;
		}
		pair<pair<int, int>, int> P=*it;
		S.erase(it);
		P.first.second--;
		if(P.first.second)
			S.insert(P);
		ans[parts[i].second]=P.second;
	}
	puts("YES");
	for(int i=0; i < n; ++i)
		printf("%d ", ans[i]+1);
}