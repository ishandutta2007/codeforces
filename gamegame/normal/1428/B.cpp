#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
char c[N];
void solve(){
	cin >> n;
	int duh=0;
	for(int i=0; i<n ;i++){
		cin >> c[i];
		if(c[i]=='<') duh|=1;
		if(c[i]=='>') duh|=2;
	}
	int ans=0;
	for(int i=0; i<n ;i++){
		if(c[i]=='-' || c[(i+n-1)%n]=='-' || duh!=3) ans++;
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}