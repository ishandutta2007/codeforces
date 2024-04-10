#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define dep(i,x,y) for(int i=(x);i>=(y);--i)
#define N 100010
using namespace std;
typedef long long ll;
int n,k,b[18][N];
inline ll cal(int l,int r){
	if(r-l+1>=n)return b[17][1];
	l=(l-1)%n+1;r=(r-1)%n+1;
	if(l>r)return min(cal(l,n),cal(1,r));
	dep(i,16,0)if((r-l+1)>>i)return min(b[i][l],b[i][r-(1<<i)+1]);
}
struct sq{
	sq*ls,*rs;int s,lz,L,R;
	sq(int l,int r){
		ls=rs=0;lz=0;L=l;R=r;s=cal(l,r);
	}
	void dw(){
		if(!lz)return;
		int m=(R+L)>>1;
		if(!ls)ls=new sq(L,m);
		if(!rs)rs=new sq(m+1,R);
		ls->lz=ls->s=rs->lz=rs->s=lz;lz=0;
	}
	void f(int l,int r,int x){
		if(l<=L&&r>=R){
			lz=s=x;return;
		}
		dw();int m=(L+R)>>1;
		if(l<=m){
			if(!ls)ls=new sq(L,m);
			ls->f(l,r,x);
		}
		if(r>m){
			if(!rs)rs=new sq(m+1,R);
			rs->f(l,r,x);
		}
		s=min(ls?ls->s:cal(L,m),rs?rs->s:cal(m+1,R));
	}
	int q(int l,int r){
		if(l==L&&r==R)return s;
		dw();int m=(L+R)>>1;
		if(r<=m)return ls?ls->q(l,r):cal(l,r);
		if(l>m)return rs?rs->q(l,r):cal(l,r);
		return min(ls?ls->q(l,m):cal(l,m),rs?rs->q(m+1,r):cal(m+1,r));
	}
};
int main(){
	scanf("%d%d",&n,&k);
	rep(i,1,n)scanf("%d",&b[0][i]);
	rep(i,0,16)rep(j,1,n){
		b[i+1][j]=b[i][j];
		if(j+(1<<i)<=n)b[i+1][j]=min(b[i+1][j],b[i][j+(1<<i)]);
	}
	sq rt(1,n*k);int m;
	scanf("%d",&m);
	while(m--){int op,l,r;
		scanf("%d%d%d",&op,&l,&r);
		if(op==1){int x;
			scanf("%d",&x);rt.f(l,r,x);
		}else printf("%d\n",rt.q(l,r));
	}
}