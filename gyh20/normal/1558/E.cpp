#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,head[1002],cnt,a[1002],b[1002],pre[1002],Qx[1002],hd,tl,Qy[1002],inf=1.1e9;
char v[1002],vis[1002];
struct edge{int to,next;}e[4002];
inline void add(re int x,re int y){e[++cnt]=(edge){y,head[x]},head[x]=cnt;}
inline bool ck(re int x){
	memset(v,0,sizeof(v)),v[1]=1;re int num=1,Sum=x;
	while(num<n){
		re int Pos=0;hd=1,tl=0;
		for(re int i=1;i<=n;++i)vis[i]=v[i],pre[i]=0;
		for(re int i=1;i<=n;++i)if(v[i])Qx[++tl]=i,Qy[tl]=Sum;
		while(hd<=tl){
			re int x=Qx[hd],y=Qy[hd++];
			for(re int i=head[x];i;i=e[i].next){
				if(y>a[e[i].to]&&(!(v[e[i].to]&&v[x]))&&e[i].to!=pre[x]){
					if(vis[e[i].to]){Pos=x;break;}
					vis[e[i].to]=1,Qx[++tl]=e[i].to,Qy[tl]=min(inf,y+b[e[i].to]),pre[e[i].to]=x;
				}
			}
		}
		if(!Pos)return 0;
		while(!v[Pos])Sum+=b[Pos],Sum=min(Sum,inf),v[Pos]=1,++num,Pos=pre[Pos];
	}return 1;
}
int main(){
	t=read(); 
	while(t--){
		n=read(),m=read(),memset(head,0,sizeof(head)),cnt=0;
		for(re int i=2;i<=n;++i)a[i]=read();
		for(re int i=2;i<=n;++i)b[i]=read();
		for(re int i=1,x,y;i<=m;++i)x=read(),y=read(),add(x,y),add(y,x);
		re int l=0,r=1e9,pos=1e9+1;
		while(l<=r){
			re int mid=l+r>>1;
			if(ck(mid))pos=mid,r=mid-1;
			else l=mid+1;
		}printf("%d\n",pos);
	}
}