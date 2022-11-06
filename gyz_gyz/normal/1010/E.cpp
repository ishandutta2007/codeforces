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
#define N 300010
#define NN 20000000
#define ll long long
#define inf 1000000000
#define Inf 1000000000000000000ll
#define mo 1000000007
#define eps 1e-8
using namespace std;
int n,m,k,tot,t1,t2,mx,my,mz,lx,rx,ly,ry,lz,rz,x,y,z;
int ans[N],t[N],l[N],r[N],a[NN],ls[NN],rs[NN];
struct po{int x,y,z;}p[N];
struct pr{int x,ly,ry,lz,rz,id;}qs[N*2];
bool cmp1(po x,po y){return x.x<y.x;}
bool cmp2(pr x,pr y){return x.x<y.x;}
void f(int x,int y,int L,int R){a[x]++;
	if((L==y)&&(R==y))return;int rr=(L+R)/2;
	if(y>rr){
		if(!rs[x])rs[x]=++t2;
		f(rs[x],y,rr+1,R);
	}else{
		if(!ls[x])ls[x]=++t2;
		f(ls[x],y,L,rr);
	}
}
void F(int x,int y,int z,int L,int R){
	if(!t[x])t[x]=++t2;f(t[x],z,1,mz);
	if((L==y)&&(R==y))return;int rr=(L+R)/2;
	if(!l[x])l[x]=++t1,r[x]=++t1;
	if(y>rr){
		if(!r[x])r[x]=++t1;
		F(r[x],y,z,rr+1,R);
	}else{
		if(!l[x])l[x]=++t1;
		F(l[x],y,z,L,rr);
	}
}
int q(int x,int l,int r,int L,int R){
	if(!x)return 0;
	if((l==L)&&(r==R))return a[x];int rr=(L+R)/2;
	if(r<=rr)return q(ls[x],l,r,L,rr);
	if(l>rr)return q(rs[x],l,r,rr+1,R);
	return q(ls[x],l,rr,L,rr)+q(rs[x],rr+1,r,rr+1,R);
}
int Q(int x,int ly,int ry,int lz,int rz,int L,int R){
	if(!x)return 0;
	if((L==ly)&&(R==ry))return q(t[x],lz,rz,1,mz);
	int rr=(L+R)/2;
	if(ry<=rr)return Q(l[x],ly,ry,lz,rz,L,rr);
	if(ly>rr)return Q(r[x],ly,ry,lz,rz,rr+1,R);
	return Q(l[x],ly,rr,lz,rz,L,rr)+Q(r[x],rr+1,ry,lz,rz,rr+1,R);
}
int main(){
	scanf("%d%d%d%d%d%d",&mx,&my,&mz,&n,&m,&k);
	lx=ly=lz=inf;rx=ry=rz=0;
	rep(i,1,n){
		scanf("%d%d%d",&x,&y,&z);
		if(x<lx)lx=x;if(x>rx)rx=x;
		if(y<ly)ly=y;if(y>ry)ry=y;
		if(z<lz)lz=z;if(z>rz)rz=z;
	}
	rep(i,1,m)scanf("%d%d%d",&p[i].x,&p[i].y,&p[i].z);
	sort(p+1,p+m+1,cmp1);t1=1;
	tot=1;qs[0]={lx-1,ly,ry,lz,rz,0};qs[1]={rx,ly,ry,lz,rz,1};
	rep(i,1,k){
		scanf("%d%d%d",&x,&y,&z);
		if((x>=lx)&&(x<=rx)&&(y>=ly)&&(y<=ry)&&(z>=lz)&&(z<=rz))ans[i]=2;else{
			qs[++tot]={min(x,lx)-1,min(y,ly),max(y,ry),min(z,lz),max(z,rz),i*2};
			qs[++tot]={max(x,rx),min(y,ly),max(y,ry),min(z,lz),max(z,rz),i*2+1};
		}
	}
	sort(qs,qs+tot+1,cmp2);x=1;
	rep(i,0,tot){y=qs[i].id>>1;
		for(;(x<=m)&&(p[x].x<=qs[i].x);x++){
			F(1,p[x].y,p[x].z,1,my);
		}
		if(qs[i].id&1){
			ans[y]+=Q(1,qs[i].ly,qs[i].ry,qs[i].lz,qs[i].rz,1,my);
			if(ans[y]>0)ans[y]=0;else ans[y]=1;
		}else ans[y]-=Q(1,qs[i].ly,qs[i].ry,qs[i].lz,qs[i].rz,1,my);
	}
	if(!ans[0]){printf("INCORRECT");return 0;}
	printf("CORRECT\n");
	rep(i,1,k)if(ans[i]==2)printf("OPEN\n");
	else if(ans[i])printf("UNKNOWN\n");else printf("CLOSED\n");
}