#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
void solve(){
	string s;cin >> s;
	bool zero=true;
	for(auto c:s){
		if(c=='0') zero=false;
	}
	if(zero){
		cout << "0\n";
	}
	else{
		while(!s.empty() && s.back()=='1') s.pop_back();
		reverse(s.begin(),s.end());
		while(!s.empty() && s.back()=='1') s.pop_back();
		bool one=true;
		for(auto c:s){
			if(c=='1') one=false;
		}
		if(one) cout << "1\n";
		else cout << "2\n";
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}