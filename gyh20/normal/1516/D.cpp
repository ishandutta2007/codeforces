#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,lst[100002],q,a[100002],f[100002],g[22][100002];
int main(){
	n=read(),q=read();
	for(re int i=1;i<=n;++i)a[i]=read();
	for(re int i=1;i<=n;++i){
		f[i]=f[i-1];
		for(re int j=2;j*j<=a[i];++j)
			if(a[i]%j==0){
				f[i]=max(f[i],lst[j]);
				lst[j]=i;
				while(a[i]%j==0)a[i]/=j;
			}
		if(a[i]^1){
			f[i]=max(f[i],lst[a[i]]);
			lst[a[i]]=i;
		}
	}
	for(re int i=1;i<=n;++i)g[0][i]=f[i];
	for(re int i=1;i<=20;++i)for(re int j=1;j<=n;++j)g[i][j]=g[i-1][g[i-1][j]];
	while(q--){
		re int l=read(),r=read(),x=0;
		for(re int i=20;~i;--i)if(g[i][r]>=l)x+=1<<i,r=g[i][r];
		printf("%d\n",x+1);
	}
}