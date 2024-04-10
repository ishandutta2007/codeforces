#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,m,t,f[15002][302],g[15002][302],a[15002],c1[302][15002],c2[302][15002];
inline void gmn(re int&x,re int y){y<x&&(x=y);}
inline void gmx(re int&x,re int y){y>x&&(x=y);}
inline void Add1(re int*c,re int x,re int y){for(;x;x^=x&(-x))gmn(c[x],y);}
inline int Ask1(re int*c,re int x,re int s=n+1){for(;x<=n;x+=x&(-x))gmn(s,c[x]);return s;}
inline void Add2(re int*c,re int x,re int y){for(;x<=n;x+=x&(-x))gmx(c[x],y);}
inline int Ask2(re int*c,re int x,re int s=0){for(;x;x^=x&(-x))gmx(s,c[x]);return s;}
struct node{int x,y,z;};
vector<node>X[15002],Y[15002];
int main(){
	t=read();
	while(t--){
		n=read();
		for(re int i=1;i<=n;++i)a[i]=read(),memset(f[i],0x3f,sizeof(f[i])),memset(g[i],0,sizeof(g[i])),X[i].clear(),Y[i].clear();
		for(re int i=0;i<=300;++i)fill(c1[i]+1,c1[i]+n+1,1145141),fill(c2[i]+1,c2[i]+n+1,0);
		for(re int i=n;i<=n;++i)f[i][1]=g[i][1]=a[i];
		re int ans=0;
		for(re int i=n;i;--i){
			for(auto z:X[i])Add1(c1[z.y],z.x,z.z);
			for(auto z:Y[i])Add2(c2[z.y],z.x,z.z);
			for(re int j=300;j;--j){
				gmn(f[i][j],Ask1(c1[j-1],a[i])),gmx(g[i][j],Ask2(c2[j-1],a[i]));
				if(f[i][j]>n&&g[i][j]<1)continue;
				ans=max(ans,j),Add1(c1[j],a[i],f[i][j]),Add2(c2[j],a[i],g[i][j]);
				if(i>j)X[i-j].push_back((node){g[i][j],j,a[i]}),Y[i-j].push_back((node){f[i][j],j,a[i]});
			}
		}
		for(re int i=1;i<=n;++i)memset(f[i],0x3f,sizeof(f[i])),memset(g[i],0,sizeof(g[i])),X[i].clear(),Y[i].clear();
		for(re int i=0;i<=300;++i)fill(c1[i]+1,c1[i]+n+1,1145141),fill(c2[i]+1,c2[i]+n+1,0);
		for(re int i=1;i<=n;++i)f[i][2]=g[i][2]=a[i];
		for(re int i=n;i;--i){
			for(auto z:X[i])Add1(c1[z.y],z.x,z.z);
			for(auto z:Y[i])Add2(c2[z.y],z.x,z.z);
			for(re int j=300;j;--j){
				gmn(f[i][j],Ask1(c1[j-1],a[i])),gmx(g[i][j],Ask2(c2[j-1],a[i]));
				if(f[i][j]>n&&g[i][j]<1)continue;
				ans=max(ans,j-1),Add1(c1[j],a[i],f[i][j]),Add2(c2[j],a[i],g[i][j]);
				if(i>j)X[i-j].push_back((node){g[i][j],j,a[i]}),Y[i-j].push_back((node){f[i][j],j,a[i]});
			}
		}
		printf("%d\n",ans);
	}
}