#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
#include<map>
#include<set>
#include<vector>
#include<bitset>
#include<algorithm>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define N 131072
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,tot,tk,al,x;
int d[N],st[N],ed[N],nt[N],f[N],ff[N];
int ps[N],pv[N],bg[N],re[N],op[N],po[N],rb[N],fx[N],we[N];
struct pr{int x,y;}a[N*2],y,z;
struct Q{int x,y;};
bool operator<(Q x,Q y){
	if(x.y==y.y)return x.x<y.x;else return x.y<y.y;
}
set<Q>s;
void dfs(int x){d[x]=1;
	for(int i=st[x];i;i=nt[i]){
		dfs(i);d[x]+=d[i];
		if(d[i]>d[bg[x]])bg[x]=i;
	}
}
void bt(int x){ps[x]=++tot;
	if(bg[x]){
		ff[bg[x]]=ff[x];bt(bg[x]);
		for(int i=st[x];i;i=nt[i])if(i!=bg[x]){
			ff[i]=i;bt(i);
		}
	}pv[x]=tot;
}
void F(int x,int y,int z,int L,int R){
	if((L==y)&&(R==y)){a[x].x+=z;a[x].y+=z;return;}int rr=(L+R)/2;
	if(y>rr)F(x*2+1,y,z,rr+1,R);else F(x*2,y,z,L,rr);
	a[x]={fmax(a[x*2+1].x,a[x*2+1].y+a[x*2].x),a[x*2].y+a[x*2+1].y};
}
pr q(int x,int l,int r,int L,int R){
	if((L==l)&&(R==r))return a[x];int rr=(L+R)/2;
	if(r<=rr)return q(x*2,l,r,L,rr);
	if(l>rr)return q(x*2+1,l,r,rr+1,R);
	pr x1=q(x*2,l,rr,L,rr);pr x2=q(x*2+1,rr+1,r,rr+1,R);
	return {fmax(x2.x,x2.y+x1.x),x1.y+x2.y};
}
int main(){
	rep(i,N,N*2-1)a[i]={-1,-1};
	dep(i,N-1,1)a[i]={-1,a[i*2].y+a[i*2+1].y};
	scanf("%d%d",&n,&m);
	rep(i,2,n){
		scanf("%d",&f[i]);
		if(!st[f[i]])st[f[i]]=i;else nt[ed[f[i]]]=i;ed[f[i]]=i;
	}
	dfs(1);ff[1]=1;bt(1);
	rep(i,1,m){
		scanf("%d%d",&op[i],&po[i]);
		if(op[i]<3){
			if(op[i]==2){
				auto x=s.lower_bound({0,ps[po[i]]+1});
				while((x!=s.end())&&(x->y<=pv[po[i]])){
					rb[++al]=i;re[x->x]=al;we[al]=x->y;
					if(op[x->x]==1)fx[al]=-1;
					s.erase(x);x=s.lower_bound({0,ps[po[i]]+1});
				}
			}
			s.insert({i,ps[po[i]]});
		}
	}tk=1;
	rep(i,1,m){
		if(op[i]==1)F(1,ps[po[i]],1,1,N);else{y={-1,0};
			for(x=po[i];x;x=f[ff[x]]){
				z=q(1,ps[ff[x]],ps[x],1,N);
				y={fmax(y.y+z.x,y.x),y.y+z.y};
			}
			if(op[i]==3){
				if(y.x<0)printf("white\n");else printf("black\n");
			}else{
				if(re[i])fx[re[i]]=y.x+1;
				F(1,ps[po[i]],-1-y.x,1,N);
				for(;(tk<=al)&&(rb[tk]==i);tk++)F(1,we[tk],fx[tk],1,N);
			}
		}
	}
}