#include<bits/stdc++.h>
#define re register
using namespace std;
inline void gmx(re int&x,re int y){y>x&&(x=y);}
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,A,B,f[2][1<<22],P,ans,tmp;
int main(){
	n=read(),A=read(),B=read(),P=(1<<max(A,B))-1;
	for(re int i=0;i<A+B;++i,tmp^=1){
		memset(f[tmp^1],0,sizeof(f[tmp^1]));
		for(re int j=0;j<=P;++j){
			gmx(f[tmp^1][(j<<1)&P],f[tmp][j]);
			if(!(j&(1<<A-1))&&!(j&(1<<B-1)))gmx(f[tmp^1][(j<<1|1)&P],f[tmp][j]+(n/(A+B))+(n%(A+B)>i));
			gmx(ans,f[tmp][j]);
		}
	}printf("%d",ans);
}