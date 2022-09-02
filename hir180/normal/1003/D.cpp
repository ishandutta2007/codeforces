#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
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
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,q;
ll x[200005];
int cnt[35];
int main(){
	cin>>n>>q;
	rep(i,n){
		cin>>x[i];
		rep(j,35){
			if((1LL<<j) == x[i]){
				cnt[j]++; break;
			}
		}
	}
	rep(i,q){
		ll a; cin>>a;
		int cnt2[35];
		rep(i,35) cnt2[i] = cnt[i];
		ll ans = 0;
		for(int j=30;j>=0;j--){
			if(a >= (1LL<<j) && cnt2[j]){
				ll d = (1LL<<j) * cnt2[j];
				if(a >= d){
					a -= d;
					ans += cnt2[j];
				}
				else{
					ans += a/(1LL<<j);
					a %= (1LL<<j);
				}
			}
		}
		if(a)
		{
			puts("-1");
		}
		else{
			cout<<ans<<endl;
		}
	}
}