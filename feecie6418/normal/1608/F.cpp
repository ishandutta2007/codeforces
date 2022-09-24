#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=998244353;
int f[105][2005],g[105][2005],s[105][2005],L[2005],R[2005],n,m,b[2005],ans=0,ny[2005]={1},jc[2005]={1};
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
void upd(int &x,int y){
	x+=y,(x>=mod?x-=mod:0);
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[n]=Power(jc[n],mod-2);
	for(int i=n-1;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	for(int i=1;i<=n;i++)cin>>b[i],L[i]=b[i]-m,R[i]=b[i]+m,R[i]=min(R[i],n),L[i]=max(L[i],0);
	L[0]=R[0]=0,f[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=R[i-1]-L[i-1];j++){
			for(int k=0;k<i;k++){
				s[j][k]=((j?s[j-1][k+1]:0)+1ll*f[j][k]*jc[k])%mod;
			}
		}
		for(int j=L[i];j<=R[i];j++){
			for(int k=0;k<=i;k++){
				if(j<=R[i-1]&&j>=L[i-1])upd(g[j-L[i]][k],1ll*f[j-L[i-1]][k]*(j+k)%mod);
				if(j<=R[i-1]&&j>=L[i-1])upd(g[j-L[i]][k],f[j-L[i-1]][k-1]);
				int X=min(j-L[i-1]-1,R[i-1]-L[i-1]);
				if(X<0)continue;
				int Y=j-L[i-1]+k-1-X;//XY 
				if(Y<0)X+=Y,Y=0;
				if(X<0)continue;
				upd(g[j-L[i]][k],1ll*ny[k]*s[X][Y]%mod);
			}
		}
		for(int j=L[i];j<=R[i];j++){
			for(int k=0;k<=i;k++)f[j-L[i]][k]=g[j-L[i]][k],g[j-L[i]][k]=0;
		}
	}
	for(int j=L[n];j<=R[n];j++){
		for(int k=0;k<=n-j;k++)upd(ans,1ll*f[j-L[n]][k]*jc[n-j]%mod*ny[n-j-k]%mod);
	}
	cout<<ans;
}