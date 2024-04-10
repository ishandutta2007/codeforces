#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int n,m,is[200005],a[200005],f[3005][3005][3],g[3005][3005][3],b[60005];
void upd(int &x,int y){
	x=(x+y)%mod;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&is[i]);
	int all0=0,all1=0,all=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(is[i])all1=(all1+a[i])%mod;
		else all0=(all0+a[i])%mod;
	}
	all=(all1+all0)%mod;
	f[0][0][0]=1;
	for(int i=-10000;i<=10000;i++)b[i+10000]=Power(all+i,mod-2);
	for(int j=0;j<m;j++){
		for(int k=0;k<=j;k++){
			int w=b[k-(j-k)+10000];
			for(int l=0;l<=1;l++){
				if(!f[j][k][l])continue;
				//1
				upd(f[j+1][k+1][l],1ll*f[j][k][l]*(all1+k)%mod*w%mod);
				// 
				upd(f[j+1][k][l],1ll*f[j][k][l]*(all0-(j-k)-(1-l))%mod*w%mod);
				// 
				upd(f[j+1][k][l+1],1ll*f[j][k][l]*(1-l)%mod*w%mod);
			}
		}
	}
	g[0][0][0]=1;
	for(int j=0;j<m;j++){
		for(int k=0;k<=j;k++){
			int w=b[k-(j-k)+10000];
			for(int l=0;l<=1;l++){
				if(!g[j][k][l])continue;
				// 
				upd(g[j+1][k+1][l+1],1ll*g[j][k][l]*(mod-1+l)%mod*w%mod);
				// 
				upd(g[j+1][k+1][l],1ll*g[j][k][l]*(all1+k)%mod*w%mod);
				upd(g[j+1][k+1][l],mod-1ll*g[j][k][l]*(mod-1+l)%mod*w%mod);
				//0
				upd(g[j+1][k][l],1ll*g[j][k][l]*(all0-(j-k))%mod*w%mod);
			}
		}
	}
	int ans1=0,ans0=0;
	for(int j=0;j<=m;j++)for(int k=0;k<=1;k++)ans1=(ans1+1ll*g[m][j][k]*(k-1+mod))%mod;
	for(int j=0;j<=m;j++)for(int k=0;k<=1;k++)ans0=(ans0+1ll*f[m][j][k]*(1-k+mod))%mod;
	for(int i=1;i<=n;i++){
		if(is[i])cout<<1ll*a[i]*(mod-ans1)%mod<<'\n';
		else cout<<1ll*a[i]*ans0%mod<<'\n';
	}
}