#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[1000005][2][2];
int n,a[1000005],b[10000005];
void upd(ll &x,ll y){
	x=min(x,y);
}
void Solve(){
	scanf("%d",&n);
	ll sumb=0;
	for(int i=1;i<=n;i++)scanf("%d",&b[i]),sumb+=b[i];
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	//1
	for(int i=1;i<=n;i++)memset(f[i],0x3f,sizeof(f[i]));
	f[1][1][0]=a[1];
	for(int i=2;i<=n;i++){
		upd(f[i][1][0],f[i-1][1][0]+a[i]);
		upd(f[i][1][0],f[i-1][1][1]+a[i]);
		upd(f[i][0][1],f[i-1][0][1]+b[i]);
		upd(f[i][0][1],f[i-1][1][0]+b[i]);
		upd(f[i][0][1],f[i-1][1][1]+b[i]);
		upd(f[i][1][1],f[i-1][0][1]+a[i]+b[i]);
		upd(f[i][1][1],f[i-1][1][0]+a[i]+b[i]);
		upd(f[i][1][1],f[i-1][1][1]+a[i]+b[i]);
	}
	ll ans=1e18;
	upd(ans,f[n][1][0]),upd(ans,f[n][1][1]);
	//1
	for(int i=1;i<=n;i++)memset(f[i],0x3f,sizeof(f[i]));
	f[1][0][1]=b[1]; 
	for(int i=2;i<=n;i++){
		upd(f[i][1][0],f[i-1][1][0]+a[i]);
		upd(f[i][1][0],f[i-1][1][1]+a[i]);
		upd(f[i][0][1],f[i-1][0][1]+b[i]);
		upd(f[i][0][1],f[i-1][1][0]+b[i]);
		upd(f[i][0][1],f[i-1][1][1]+b[i]);
		upd(f[i][1][1],f[i-1][0][1]+a[i]+b[i]);
		upd(f[i][1][1],f[i-1][1][0]+a[i]+b[i]);
		upd(f[i][1][1],f[i-1][1][1]+a[i]+b[i]);
	}
	upd(ans,f[n][1][0]),upd(ans,f[n][1][1]),upd(ans,f[n][0][1]);
	//1
	for(int i=1;i<=n;i++)memset(f[i],0x3f,sizeof(f[i]));
	f[1][1][1]=a[1]+b[1];
	for(int i=2;i<=n;i++){
		upd(f[i][1][0],f[i-1][1][0]+a[i]);
		upd(f[i][1][0],f[i-1][1][1]+a[i]);
		upd(f[i][0][1],f[i-1][0][1]+b[i]);
		upd(f[i][0][1],f[i-1][1][0]+b[i]);
		upd(f[i][0][1],f[i-1][1][1]+b[i]);
		upd(f[i][1][1],f[i-1][0][1]+a[i]+b[i]);
		upd(f[i][1][1],f[i-1][1][0]+a[i]+b[i]);
		upd(f[i][1][1],f[i-1][1][1]+a[i]+b[i]);
	}
	upd(ans,f[n][1][0]),upd(ans,f[n][1][1]),upd(ans,f[n][0][1]);
	if(ans==sumb)puts("YES");
	else puts("NO");
} 
int main(){
	int t;
	scanf("%d",&t);
	while(t--)Solve();
}