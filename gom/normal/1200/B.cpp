#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef pair<int,ll> P;
const int N=2005;
const ll mod=1e9+7;
ll t,h[N],n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		cin>>h[i];
	}
	for(int i=2;i<=n;i++){
		ll ch=max(0LL,h[i]-k);
		if(h[i-1]<ch){
			ll v=ch-h[i-1];
			if(v>m){
				cout<<"NO\n";
				return;
			}
			m-=v;
		}
		else m+=h[i-1]-ch;
	}
	cout<<"YES\n";
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
	cin>>t;
	while(t--) solve();
    return 0;
}