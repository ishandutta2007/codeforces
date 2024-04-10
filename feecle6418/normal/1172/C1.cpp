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
int n,m,is[200005],a[200005],f[55][55][55];
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
	for(int i=1;i<=n;i++){
		if(is[i]){
			memset(f,0,sizeof(f));
			f[0][0][0]=1;
			for(int j=0;j<m;j++){
				for(int k=0;k<=j;k++){
					for(int l=0;l<=j;l++){
						if(!f[j][k][l])continue;
						// 
						upd(f[j+1][k+1][l+1],1ll*f[j][k][l]*(a[i]+l)%mod*Power(all+k-(j-k),mod-2)%mod);
						// 
						upd(f[j+1][k+1][l],1ll*f[j][k][l]*(all1+k-(a[i]+l))%mod*Power(all+k-(j-k),mod-2)%mod);
						//0
						upd(f[j+1][k][l],1ll*f[j][k][l]*(all0-(j-k))%mod*Power(all+k-(j-k),mod-2)%mod);
					}
				}
			}
			int ans=0;
			for(int j=0;j<=m;j++)for(int k=0;k<=m;k++)ans=(ans+1ll*f[m][j][k]*(a[i]+k))%mod;
			cout<<ans<<'\n';
		}
		else {
			memset(f,0,sizeof(f));
			f[0][0][0]=1;
			for(int j=0;j<m;j++){
				for(int k=0;k<=j;k++){
					for(int l=0;l<=j;l++){
						if(!f[j][k][l])continue;
						//1
						upd(f[j+1][k+1][l],1ll*f[j][k][l]*(all1+k)%mod*Power(all+k-(j-k),mod-2)%mod);
						// 
						upd(f[j+1][k][l],1ll*f[j][k][l]*(all0-(j-k)-(a[i]-l))%mod*Power(all+k-(j-k),mod-2)%mod);
						// 
						upd(f[j+1][k][l+1],1ll*f[j][k][l]*(a[i]-l)%mod*Power(all+k-(j-k),mod-2)%mod);
					}
				}
			}
			int ans=0;
			for(int j=0;j<=m;j++)for(int k=0;k<=m;k++)ans=(ans+1ll*f[m][j][k]*(a[i]-k))%mod;
			cout<<ans<<'\n';
		}
	}
}