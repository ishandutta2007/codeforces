#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=1e6+1;
int n,m;
int a[N];
int b[N];
int f[2*N];
int g[2*N];
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	for(int i=n; i>=1 ;i--) cin >> b[i];
	for(int i=0; i<=2*n ;i++){
		f[i]=g[i]=-1;
	}
	f[n]=g[n]=0;
	int x=n;
	for(int i=1; i<=n ;i++){
		if(a[i]==1) x++;
		else x--;
		f[x]=i;
	}
	int y=n;
	int ans=2*n;
	ans=min(ans,2*n-f[n]);
	for(int i=1; i<=n ;i++){
		if(b[i]==1) y--;
		else y++;
		if(f[y]!=-1) ans=min(ans,2*n-(f[y]+i)); 
	}
	cout << ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int t;cin >> t;while(t--) solve();
}