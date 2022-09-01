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
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
ll la,ra,ta;
ll lb,rb,tb;
ll gcdd(ll a,ll b){
	if(a<b)swap(a,b);
	if(b==0) return a;
	return gcdd(b,a%b);
}
int main(){
	cin>>la>>ra>>ta;
	cin>>lb>>rb>>tb;
	if(ta < tb){
		swap(la,lb);
		swap(ra,rb);
		swap(ta,tb);
	}
	ll x = gcdd(ta,tb);
	//lb = ? (mod x)
	ll rm = lb%x;
	ll dv = la/x;
	ll ans = 0;
	for(ll i=dv-30000;i<=dv+30000;i++){
		ll val = i*x+rm;
		if(1){
			//[la,ra]
			//[val,val+rb-lb]
			ll L = val;
			ll R = val+rb-lb;
			R = min(R,ta-1);
			ans = max(ans,min(R,ra)-max(L,la)+1LL);
		}
	}
	cout<<ans<<endl;
}