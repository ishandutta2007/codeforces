#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n;
ll a[200005],mx=0;
map<ll,ll> f;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	f[a[1]-1]=0;
	for(int i=2;i<=n;i++){
		while(1){
			auto k=f.lower_bound(a[i]);
			if(k==f.end())break;
			auto j=*k;
			ll x=j.first,y=j.second;
			f[x%a[i]]=max(f[x%a[i]],y+(x-x%a[i])*(i-1));
			if(x>=a[i]){
				ll z=(x-a[i]+1)/a[i]*a[i]+a[i]-1;
				f[a[i]-1]=max(f[a[i]-1],y+(z-a[i]+1)*(i-1));
			}
			f.erase(k);
		}
	}
	for(auto i:f)mx=max(mx,i.first*n+i.second);
	cout<<mx;
}