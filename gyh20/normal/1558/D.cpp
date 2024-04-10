#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=998244353;
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
inline void Add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
int n,m,fac[400003],inv[400003],siz[400003],val[400003],tg[400003],tr[400003][2],num[400003],root,fa[400003],w,cnt,TG[400003];
inline int C(re int x,re int y){return 1ll*fac[x]*inv[y]%M*inv[x-y]%M;}
inline void pu(re int p){
	siz[p]=siz[tr[p][0]]+siz[tr[p][1]]+num[p];
}
inline void pd(re int x){
	if(!x)return;
	val[x]+=tg[x];
	if(tr[x][0])tg[tr[x][0]]+=tg[x];
	if(tr[x][1])tg[tr[x][1]]+=tg[x];
	tg[x]=0;
}
inline void Pd(re int p){
	if(p^root)Pd(fa[p]);
	pd(p);
}
inline void add(re int p,re int v){
	pd(p);
	if(val[p]==v)++num[p],++siz[w=p];
	else if(val[p]>v&&tr[p][0])add(tr[p][0],v);
	else if(val[p]<v&&tr[p][1])add(tr[p][1],v);
	else{
		if(val[p]>v)tr[p][0]=++cnt;
		if(val[p]<v)tr[p][1]=++cnt;
		siz[cnt]=1,val[cnt]=v,num[cnt]=1,fa[w=cnt]=p;
	}
	pu(p);
}
inline void rotate(re int p,re int &f){
	int x=fa[p],y=fa[x];
	int s=(p!=tr[x][0]),t=(s^1);
	if(x^f)tr[y][(tr[y][0]!=x)]=p;
	else f=p;
	fa[fa[x]=p]=y;
	fa[tr[x][s]=tr[p][t]]=x;
	pu(tr[p][t]=x),pu(p);
}
inline void splay(re int p,re int &rt){
	Pd(p);
	while(p^rt){
		int x=fa[p],y=fa[x];
		if(x^rt)if((tr[x][0]==p)^(tr[y][0]==x))rotate(p,rt);
		else rotate(x,rt);
		rotate(p,rt);
	}
}
inline int find(re int p,re int x){
	if(!p)return 0;
	pd(p);
	if(val[p]<x)return find(tr[p][1],x);
	else{
		re int s=find(tr[p][0],x);
		if(!s)return p;
		else return s;
	}
}
int main(){
	n=400001;
	for(re int i=fac[0]=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%M;
	inv[n]=ksm(fac[n],M-2);
	for(re int i=n-1;~i;--i)inv[i]=1ll*inv[i+1]*(i+1)%M;
	int t=read();
	while(t--){
		n=read()-1,m=read();
		for(re int i=1;i<=cnt;++i)val[i]=tg[i]=tr[i][0]=tr[i][1]=num[i]=fa[i]=siz[i]=TG[i]=0;
		val[1]=1e9,val[tr[1][0]=2]=-1e9;
		siz[2]=fa[siz[1]=cnt=2]=root=num[1]=num[2]=1;
		re int k=m;
		for(re int i=1;i<=k;++i){
			re int x=read(),y=read();
			re int z=find(root,y);splay(z,root);
			re int tttt=find(root,y-1);
			if(val[tttt]==y-1&&TG[tttt]==0)--m,TG[tttt]=1;
			assert(z==root);
			val[z]+=1,tg[tr[z][1]]+=1;
			add(root,y),splay(w,root);
		}
		re int ans=C(2*n-m+1,n+1);
		printf("%d\n",ans);
	}
}