#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
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
int q;
ll a[200005];
int main(){
	scanf("%d",&q);
	while(q--){
		int n,k; scanf("%d%d",&n,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		if(k == 1){
			ll sum=0;repn(i,n)sum+=a[i];
			if(sum%2==1) {puts("YES"); printf("%d\n",n);}
			else puts("NO");
			continue;
		}
		ll sum = 0;repn(i,n)sum+=a[i];
		if(sum%2 != k%2) { puts("NO"); continue;}
		vector<int>pos;
		ll cur = 0;
		bool ok = 0;
		for(int i=1;i<=n;i++){
			cur += a[i];
			if(cur%2 == 1){
				pos.pb(i);
				cur = 0;
				if(pos.size()==k-1) {if(i!=n) ok = 1; break;}
			}
		}
		if(!ok){puts("NO"); continue;}
		pos.pb(n);
		puts("YES");
		rep(i,k) printf("%d ",pos[i]); puts("");
	}}