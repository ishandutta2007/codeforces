#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,q,jc[3000005],ny[3000005],f[3000005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int main(){
	cin>>n>>q,jc[0]=ny[0]=1;
	for(int i=1;i<=3000003;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[3000003]=Power(jc[3000003],mod-2);
	for(int i=3000002;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	//f[0][0]=f[0][1]=f[0][2]=n+1;
	for(int i=0;i<=2;i++)for(int k=0;k<=n;k++)f[i]=(f[i]+C(3*k,i))%mod;
	for(int i=3;i<=3*n;i++){
		f[i]=(C(3*n+3,i+1)-3ll*f[i-1]-f[i-2]+4ll*mod)%mod;
		f[i]=1ll*f[i]*(mod+1)/3%mod;
		//if(i>=3)cout<<C(3*n+3,i)<<' '<<3*f[i-1][0]+3*f[i-2][0]+f[i-3][0]<<'\n';
		//puts("");
	}
	for(int i=1;i<=q;i++){
		int x;
		scanf("%d",&x),printf("%d\n",f[x]);
	}
	return 0;
}