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
int n,m;
ll sm[100005],bg[100005],mul[100005];
vector<int>in[100005];
vector<int>edge[100005];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,m){
		int a,b; scanf("%d%d",&a,&b);
		edge[a].pb(b);
		edge[b].pb(a);
	}
	ll ans = 0;
	repn(i,n){
		rep(j,edge[i].size()){
			if(i > edge[i][j]){
				sm[i]++;
			}
			else{
				bg[i]++;
				in[i].pb(edge[i][j]);
			}
		}
		mul[i] = sm[i]*bg[i];
		ans += mul[i];
	}
	int q; scanf("%d",&q);
	printf("%lld\n",ans);
	rep(i,q){
		int a; scanf("%d",&a);
		ans -= sm[a]*bg[a];
		sm[a] = edge[a].size(); bg[a] = 0;
		
		rep(j,in[a].size()){
			int to = in[a][j];
			ans -= sm[to]*bg[to];
			ans += (sm[to]-1)*(bg[to]+1);
			sm[to]--; bg[to]++; in[to].pb(a);
		}
		in[a].clear();
		printf("%lld\n",ans);
	}
}