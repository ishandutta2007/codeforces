#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int n,bl[3000002],w[3000002],k,cnt,m,tot,vis[3000002],v[3000002],rt[3000002];
vector<int>g[3000002];
struct edge{
	int x,y;
	bool operator <(const edge a)const{
		if(bl[x]!=bl[a.x])return bl[x]<bl[a.x];
		if(bl[y]!=bl[a.y])return bl[y]<bl[a.y];
		return x<a.x;
	}
	bool operator ==(const edge a)const{
		return (bl[x]==bl[a.x])&&(bl[y]==bl[a.y]);
	}
}e[3000002];
struct dsu{
	int fa[3000002],siz[3000002],stkx[3000002],stky[3000002],tp,sum,tag[3000002];
	inline void init(){for(re int i=1;i<=tot;++i)siz[fa[i]=i]=1;}
	inline int root(re int x){if(!tag[x])sum^=1;return x==fa[x]?x:root(fa[x]);}
	inline int merge(re int x,re int y,re int zz=0){
		re int xx=root(x),yy=root(y);
		if(xx!=yy){
			if(siz[xx]>siz[yy])swap(xx,yy);
			stkx[++tp]=xx,stky[++tp]=yy;
			fa[xx]=yy,siz[yy]+=siz[xx];
			tag[xx]=zz;
		}
	}
	inline int ask(re int x,re int y){
		sum=0;
		re int xx=root(x),vx=sum;
		sum=0;
		re int yy=root(y),vy=sum;
		if(xx==yy){
			if(vx^vy)return 0;
			else return 1;
		}
		else {
			if(vx==vy)merge(xx,yy);
			else merge(xx,yy,1);
			return 0;
		}
	}
	inline int ask(re int x){
		sum=0;
		root(x);
		return sum;
	}
	inline void undo(re int lst){
		while(tp>lst){
			siz[stky[tp]]-=siz[stkx[tp]];
			fa[stkx[tp]]=stkx[tp];
tag[stkx[tp]]=0;
			--tp;
		}
	}
}D1,D2;
long long ans;
int main(){
	n=read(),m=read(),k=read(),tot=n;
	D1.init();
	for(re int i=1;i<=n;++i)bl[i]=read();
	for(re int i=1,x,y;i<=m;++i){
		x=read(),y=read();
		if(bl[x]>bl[y])swap(x,y);
		if(bl[x]==bl[y]){
			if(D1.ask(x,y)){vis[bl[x]]=1;}
		}
		else{
			e[++cnt]=(edge){x,y};
		}
	}
	ans=1ll*k*(k-1)/2;
	if(tot&1)++tot;
	re int xx=tot+2;
	for(re int i=1;i<=n;++i)if(!v[D1.root(i)])tot+=2,v[D1.root(i)]=tot;tot+=2;
	D2.init();
	while(xx<=tot)D2.merge(xx+1,xx),xx+=2;
	for(re int i=1;i<=n;++i)vis[bl[i]]|=D2.ask(i,rt[i]=(v[D1.root(i)]+D1.ask(i)));
	sort(e+1,e+cnt+1);
	re int sum=1;
	for(re int i=1;i<=k;++i)if(vis[i])ans-=k-sum,++sum;
	for(re int i=1,j;i<=cnt;i=j+1){
		j=i;
		while(e[j]==e[j+1])++j;
		re int xx=D2.tp,yy=bl[e[i].x],zz=bl[e[i].y];
		if(vis[yy]||vis[zz])continue;
		for(re int k=i;k<=j;++k){
			if(D2.ask(e[k].x,e[k].y)){
				--ans;
				break;
			}
		}
		D2.undo(xx);
	}
	printf("%lld",ans);
}