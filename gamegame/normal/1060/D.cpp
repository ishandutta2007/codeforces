#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
ll l[100001];
ll r[100001];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);int n;
	ll ans=0;
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> l[i] >> r[i];
	sort(l+1,l+n+1);
	sort(r+1,r+n+1);
	for(int i=1; i<=n ;i++) ans+=max(l[i],r[i]);
	cout << ans+n << endl;
}