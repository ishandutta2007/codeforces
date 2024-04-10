/*#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")*/
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
#define mod 998244353
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
int n,p[1005],q[1005];
vector<P2>ans;
int main(){	
	scanf("%d",&n);
	repn(i,n) cin>>p[i];
	repn(i,n) cin>>q[i];
	for(int i=n;i>=1;i--){
		if(p[i] == i && q[i] == i) continue;
		if(p[i] == i){
			repn(j,n) if(q[j] == i){
				ans.pb(P2(P(i,q[i]),P(i,i)));
				swap(q[j],q[i]);
				break;
			}
		}
		else if(q[i] == i){
			repn(j,n) if(p[j] == i){
				ans.pb(P2(P(p[i],i),P(i,i)));
				swap(p[j],p[i]);
				break;
			}
		}
		else{
			int x,y;
			repn(j,n) if(q[j] == i){
				y = j; break;
			}
			repn(j,n) if(p[j] == i){
				x = j;
				break;
			}
			ans.pb(P2(P(i,q[i]),P(p[i],i)));
			swap(p[x],p[i]);
			swap(q[y],q[i]);
		}
	}
	cout << ans.size() << endl;
	rep(i,ans.size()) cout << ans[i].fi.fi << " " << ans[i].fi.sc << " " << ans[i].sc.fi << " " << ans[i].sc.sc << endl;
}