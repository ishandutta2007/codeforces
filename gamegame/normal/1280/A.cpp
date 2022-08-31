#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
void solve(){
	int x;cin >> x;
	string s;cin >> s;
	ll len=s.size();
	for(int i=1; i<=x ;i++){
		ll cur=s[i-1]-48;
		len=(len+1LL*(cur-1)*(len-i))%mod;
		len=(len+mod)%mod;
		if(s.size()>=3*x) continue;
		ll p=s.size();
		for(int j=0; j<cur-1 ;j++){
			for(int k=i; k<p ;k++) s+=s[k];
		}
	}
	cout << len << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}