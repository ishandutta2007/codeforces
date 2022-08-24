#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		cin >> n;
		int sa=0,sb=0;
		for(int i=1; i<=2*n ;i++){
			ll x,y;cin >> x >> y;
			if(x==0){
				b[++sb]=abs(y);
			}
			else{
				a[++sa]=abs(x);
			}
		}
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		double ans=0;
		for(int i=1; i<=n ;i++){
			ans=ans+sqrt(a[i]*a[i]+b[i]*b[i]);
		}
		printf("%.10f\n",ans);
	}
}