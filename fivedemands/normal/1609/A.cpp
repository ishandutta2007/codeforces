#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		cin >> n;
		ll fuck=0;
		ll mx=0;
		ll s=0;
		for(int i=1; i<=n ;i++){
			cin >> a[i];
			while(a[i]%2==0){
				fuck=fuck*2+1;
				a[i]/=2;
			}
			mx=max(mx,a[i]);
			s+=a[i];
		}
		cout << s+mx*fuck << '\n';
	}
}