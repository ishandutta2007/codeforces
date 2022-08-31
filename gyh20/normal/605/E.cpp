#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n;
double g[1002][1002],e[1002],p[1002];
bool vis[1002];
int main(){
	n=read();
	for(re int i=1;i<=n;++i)for(re int j=1;j<=n;++j)g[i][j]=0.01*read();
	vis[n]=1;
	for(re int i=1;i<=n;++i)e[i]=1,p[i]=1-g[i][n];
	if(n==1)return puts("0.00000000"),0;
	for(re int i=1;i<=n;++i){
		re double mn=1e18;
		re int pos;
		for(re int j=1;j<=n;++j)if(!vis[j]&&e[j]/(1-p[j])<mn)mn=e[j]/(1-p[j]),pos=j;
		vis[pos]=1;
		if(pos==1)return printf("%.12lf",mn),0;
		for(re int j=1;j<=n;++j)e[j]+=e[pos]/(1-p[pos])*g[j][pos]*p[j],p[j]*=(1-g[j][pos]);
	}
}