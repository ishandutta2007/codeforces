#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	set<int>s;
	for(int i=1; i<=n ;i++) s.insert(i);
	ll ans=0;
	for(int i=1; i<=n ;i++){
		if(s.find(a[i])!=s.end()){
			s.erase(a[i]);a[i]=0;
		}
	}
	for(int i=1; i<=n ;i++){
		if(a[i]!=0){
			ll x=(a[i]+1)/2;
			auto it=s.lower_bound(x);
			if(it!=s.begin()){
				--it;s.erase(it);ans++;
			}
			else{
				cout << "-1\n";
				return;
			}
		}
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		solve();
	}
}