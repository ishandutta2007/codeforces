#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
typedef long long ll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
int n;
vector<P>edge;
queue<int>que;
int deg[(1<<16)+5],v[(1<<16)+5];
int main()
{
	int n; scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&deg[i],&v[i]);
		if(deg[i] == 1) que.push(i);
	}
	while(!que.empty())
	{
		int q = que.front(); que.pop();
		if(deg[q] == 0) continue;
		edge.pb(mp(q,v[q]));
		deg[v[q]]--;
		v[v[q]] ^= q;
		if(deg[v[q]] == 1)
		{
			que.push(v[q]);
		}
	}
	printf("%d\n",edge.size());
	for(int i=0;i<edge.size();i++) printf("%d %d\n",edge[i].fi,edge[i].sc);
}