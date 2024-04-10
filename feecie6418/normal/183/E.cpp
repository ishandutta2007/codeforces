#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int n,m;
ll a[200005],b[200005],ans=0; 
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=m/n;i++){
		ll t=1ll*i*(m+m-(i-1)*n)/2;
		for(int j=n;j>=1;j--)t=min(t,a[j]),b[j]=t,t-=i;
		if(b[1]<1ll*i*(1+1+(i-1)*n)/2)continue;
		ll L=max(1ll,b[1]-1ll*(i-1)*(m-n+1+m-n+1-(i-2)*n)/2);
		ll lef=m-L+1-i,sum=b[1],cur=b[1];
		for(int j=2;j<=n;j++){
			ll u=min(lef-(n-j)*i,b[j]-cur);
			cur+=u,sum+=cur,lef-=u;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
}