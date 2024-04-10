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

vector<int> adj[100005];
int d[100005];
int pre[100005];
int dN[100005];
int main(){
	int m, k, p;
	scanf("%d%d%d", &m, &k, &p);
	for(int i=0; i < m-1; ++i){
		int a, b;
		scanf("%d%d", &a, &b);
		--a;--b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	d[0]=0;
	queue<int> q;
	q.push(0);
	pre[0]=-1;
	++dN[0];
	while(!q.empty()){
		int c=q.front();
		q.pop();
		for(int i=0; i < adj[c].size(); ++i){
			int t=adj[c][i];
			if(t == pre[c])
				continue;
			d[t]=d[c]+1;
			pre[t]=c;
			++dN[d[t]];
			q.push(t);
		}
	}
	long long cost=0;
	int pos=1;
	int total=0;
	int removed=0;
	int ans=1;
	for(int i=1; i < 100005; ++i){
		cost += total-removed;
		total += dN[i];
		while(cost > p){
			while(!dN[pos])
				pos++;
			--dN[pos];
			++removed;	
			cost -= i-pos;
		}
		int newAns=total-removed;
		if(newAns > ans)
			ans=newAns;
	}
	if(ans > k)
		ans=k;
	printf("%d\n", ans);
	return 0;
}