#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
int n;
ll p;
ll a[1000001];
ll pw(ll x,ll y){
	if(y==0) return 1;
	if(y%2) return x*pw(x,y-1)%mod;
	ll res=pw(x,y/2);
	return res*res%mod;
}
void solve(){
	cin >> n >> p;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	if(p==1){
		cout << n%2 << '\n';
		return;
	}
	sort(a+1,a+n+1);
	stack<pair<int,int> >s,t;
	for(int i=n; i>=1 ;i--){
		if(s.empty()){
			s.push({a[i],1});
			continue;
		}
		else{
			if(!t.empty() && t.top().fi==a[i]) t.top().se++;
			else t.push({a[i],1});
			while(!t.empty() && t.top().se==p){
				ll x=t.top().fi+1;
				t.pop();
				if(!t.empty() && t.top().fi==x) t.top().se++;
				else t.push({x,1});
			}
			while(!s.empty() && !t.empty()){
				if(s.top().fi!=t.top().fi) break;
				s.top().se-=t.top().se;
				t.pop();
				if(s.top().se==0) s.pop();
			}
		}
	}
	ll ans=0;
	while(!s.empty()){
		ll x=s.top().fi;ll y=s.top().se;s.pop();
		ans=(ans+y*pw(p,x))%mod;
	}
	while(!t.empty()){
		ll x=t.top().fi;ll y=t.top().se;t.pop();
		ans=(ans-y*pw(p,x))%mod;
		ans=(ans+mod)%mod;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}