#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const int N=2e6+1;
const ll mod=1e9+7;
ll n,m;
ll a[N],b[N];

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++) cin >> a[i];
	ll ans=0;
	for(int i=1; i<=n ;i+=2){
		ll sum=a[i];
		ll mn=a[i];
		for(int j=i+1; j<=n ;j++){
			if(j%2==1){
				sum+=a[j];
				continue;
			}
			{//end here
				ll sn=max(1LL,a[i]-mn);
				ll sx=min(a[i],a[i]-sum+a[j]);
				if(sn<=sx) ans+=sx-sn+1;
				//cout << i << ' ' << j << ' ' << sn << ' ' << sx << endl;
			}
			sum-=a[j];
			mn=min(mn,sum);
			if(mn<0) break;
		}
	}
	cout << ans << '\n';
}