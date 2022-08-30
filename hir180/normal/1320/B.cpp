#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int dist[200005];
bool used[200005];
int force[200005];

vector<int>edge[200005],redge[200005];
int n,m;
int k,a[200005];;



int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge[b].pb(a);
		redge[a].pb(b);
	}
	scanf("%d",&k);
	repn(i,k) scanf("%d",&a[i]);
	int s = a[1], t = a[k];
	queue<int>que; que.push(t);
	rep(i,200005) dist[i] = INF;
	dist[t] = 0;
	while(!que.empty()){
		int q = que.front(); que.pop();
		if(used[q]) continue; used[q] = 1;
		rep(i,edge[q].size()){
			int to = edge[q][i];
			dist[to] = min(dist[to],dist[q]+1);
			if(!used[to]) que.push(to);
		}
	}
//	repn(i,n) cout << i << " " << dist[i] << endl;
	int mn = 0, mx = 0;
	for(int i=1;i<=n;i++){
		if(i == t) continue;
		int cnt = 0;
		rep(j,redge[i].size()){
			int to = redge[i][j];
			if(dist[to]+1 == dist[i]){
				force[i] = to;
				cnt++;
			}
		}
		assert(cnt > 0);
		if(cnt >= 2) force[i] = -1;
	}
	for(int i=1;i<k;i++){
		int x = a[i], y = a[i+1];
		if(dist[y]+1 != dist[x]){
			mn++; mx++;
		}
		else{
			mx++;
			if(force[x] == y) mx--;
		}
	}
	printf("%d %d\n",mn,mx);
}