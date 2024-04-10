#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0,f=0;re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return f?-t:t;
}
const int M=998244353;
inline void add(re int &x,re int y){(x+=y)>=M?x-=M:x;}
inline int Mod(re int x){return x>=M?x-M:x;}
inline int ksm(re int x,re int y){
	re int s=1;
	while(y){
		if(y&1)s=1ll*s*x%M;
		x=1ll*x*x%M,y>>=1;
	}
	return s;
}
int t,n,m,p[4],ans;
struct node{
	int x,y,c,id;
	bool operator <(const node A)const{return x==A.x?c<A.c:x<A.x;}
};
vector<node>a[4],A[4],G,T;
int vis[1000002];
inline bool ck1(re int x){
	re int o=1,k=x;
	for(re int i=0;i<G.size();++i){
		if(G[i].c==o)--k;
		if(!k){
			while(i!=G.size()-1&&G[i].x==G[i+1].x)++i;
			k=x,++o;
		}
	}
	return o==4;
}
inline bool cmp(re node x,re node y){return x.y==y.y?x.c>y.c:x.y<y.y;}
int tim;
inline bool ck2(re int x){
	re int k=x,o=1;++tim;
	for(re int i=0;i<G.size();++i){
		if(G[i].c==o)--k;vis[G[i].id]=tim;
		if(!k){
			while(i!=G.size()-1&&G[i].x==G[i+1].x)++i,vis[G[i].id]=tim;
			break;
		}
	}
	o=2,k=x;
	for(re int i=0;i<T.size();++i){
		if(vis[T[i].id]==tim)continue;
		if(T[i].c==o)--k;
		if(!k){
			while(i!=T.size()-1&&T[i].y==T[i+1].y)++i;
			k=x,++o;
		}
	}
	return o==4;
}
inline void work(re int dx,re int dy,re int oo=0){G.clear();
	for(re int i=1;i<=3;++i)a[i]=A[p[i]];
	for(re int i=1;i<=3;++i)
		for(re int j=0;j<a[i].size();++j){
			a[i][j].x*=dx,a[i][j].y*=dy;
			if(oo)swap(a[i][j].x,a[i][j].y);G.push_back((node){a[i][j].x,a[i][j].y,i,a[i][j].id});
		}
	T=G;
	sort(T.begin(),T.end(),cmp);
	sort(G.begin(),G.end());
	re int l=1,r=n/3,pos=0;
	while(l<=r){
		re int mid=l+r>>1;
		if(ck1(mid))pos=mid,l=mid+1;
		else r=mid-1;
	}
	ans=max(ans,pos);
	l=1,r=n/3,pos=0;
	while(l<=r){
		re int mid=l+r>>1;
		if(ck2(mid))pos=mid,l=mid+1;
		else r=mid-1;
	}
	ans=max(ans,pos);
}
int main(){
	n=read();
	for(re int i=1,x,y,z;i<=n;++i){
		x=read(),y=read(),z=read();
		A[z].push_back((node){x,y,0,i});
	}
	for(re int i=1;i<=3;++i)p[i]=i;
	do{
		work(1,-1),work(-1,1),work(1,1),work(-1,-1);
		work(1,-1,1),work(-1,1,1),work(1,1,1),work(-1,-1,1);
	}while(next_permutation(p+1,p+3+1));
	printf("%d",ans*3);
}