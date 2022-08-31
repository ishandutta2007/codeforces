#include<cstdio>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,f[1<<19],mx[1<<19],mn[1<<19],inf=1<<25;
inline void gmn(re int &x,re int y){(y<x)&&(x=y);}
inline void gmx(re int &x,re int y){(y>x)&&(x=y);}
int main(){
	m=read(),n=read();
	for(re int i=0;i<(1<<n);++i)mx[i]=-inf,mn[i]=f[i]=inf;
	for(re int i=1;i<=m;++i){
		re int x=read();
		mx[x]=mn[x]=0;
	}
	for(re int i=0;i<n;++i)
		for(re int j=0;j<(1<<n);++j){
			re int z=1<<i;
			if(!(j&z)){
				gmn(f[j],f[j+z]),gmn(f[j+z],f[j]);
				gmn(f[j],mn[j+z]-mx[j]+z),gmn(f[j+z],mn[j]-mx[j+z]+z);
				re int x=mx[j+z],y=mx[j];
				gmx(mx[j],x+z),gmx(mx[j+z],y+z);
				x=mn[j+z],y=mn[j];
				gmn(mn[j],x+z),gmn(mn[j+z],y+z);
			}
		}
	for(re int i=0;i<(1<<n);++i)printf("%d ",f[i]);
}