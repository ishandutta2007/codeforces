#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
char c[N];
ll l[N],r[N];
void solve(){
	cin >> n >> m;
	for(int i=1; i<=n ;i++){
		cin >> c[i];
	}
	l[0]=l[n+1]=r[0]=r[n+1]=2e9;
	for(int i=1; i<=n ;i++){
		if(c[i]=='1') l[i]=0;
		else l[i]=l[i-1]+1;
	}
	for(int i=n; i>=1 ;i--){
		if(c[i]=='1') r[i]=0;
		else r[i]=r[i+1]+1;
	}
	for(int i=1; i<=n ;i++){
		if(l[i]==r[i]) continue;
		if(min(l[i],r[i])<=m) c[i]='1'; 
	}
	for(int i=1; i<=n ;i++){
		cout << c[i];
	}
	cout << '\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}