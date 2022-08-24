#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
string s,t;
int n,m;
void solve(){
	cin >> s >> t;
	n=s.size(),m=t.size();
	int pos=(n+m)%2;
	int cur=0;
	while(pos<n){
		if(cur!=m && s[pos]==t[cur]){
			pos++;cur++;
		}
		else pos+=2;
	}
	if(cur==m) cout << "YES\n";
	else cout << "NO\n";
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}