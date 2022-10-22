#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

set<pair<pair<int, int>, int> > done;
int c[28], n;
bool ans=0;

void dfs(pair<pair<int, int>, int> p){
	//printf("%d %d %d\n", p.first.first, p.first.second, p.second);
	if(p.first.second == n){
		if(p.first.first == (1<<(n-1)))
			ans=1;
		return;
	}
	if(ans)
		return;
	if(done.find(p) != done.end())
		return;
	done.insert(p);
	if(p.second == 1){
		dfs(make_pair(make_pair(p.first.first, p.first.second+1), c[p.first.second+1]));
	}
	for(int i=0; i < p.first.second; ++i){
		if(i && c[i] == c[i-1] && (p.first.first&(1<<(i-1))))
			continue;
		if(!(p.first.first&(1<<i)))
			continue;
		if(p.second-c[i] <= 0 || c[i]+1 == c[p.first.second])
			break;
		dfs(make_pair(make_pair(p.first.first^(1<<i), p.first.second), p.second-c[i]));
	}
}

int main(){
	scanf("%d", &n);
	for(int i=0; i < n; ++i){
		scanf("%d", c+i);
	}
	sort(c, c+n);
	dfs(make_pair(make_pair((1<<n)-1, 0), c[0]));
	puts(ans?"YES":"NO");
	return 0;
}