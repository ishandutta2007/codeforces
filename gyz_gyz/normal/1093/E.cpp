#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define pb push_back
using namespace std;
typedef long long ll;
const int N=2e6+10;
struct chg{int t,x,y,z;};
struct que{int t,lx,rx,ly,ry,id;};
typedef vector<chg>vc;
typedef vector<que>vq;
int n,A[N],B[N],a[N],ans[N];
void cg(int x,int y){
	for(;x<=n;x+=x&(-x))a[x]+=y;
}
int qs(int x){int y=0;
	for(;x;x-=x&(-x))y+=a[x];return y;
}
void sol(int l,int r,vc&c,vq&q){
	vc cl,cr;vq ql,qr;auto x=c.begin();int m=(l+r)>>1;
	for(auto &i:q){
		for(;x!=c.end()&&x->t<=i.t;++x)cg(x->y,x->z);
		if(i.lx<=l&&i.rx>=r)ans[i.t]+=qs(i.ry)-qs(i.ly-1);else{
			if(i.lx<=m)ql.pb(i);
			if(i.rx>m)qr.pb(i);
		}
	}
	while(x!=c.begin()){
		--x;cg(x->y,-(x->z));
	}
	if(l==r)return;
	for(auto &i:c)if(i.x<=m)cl.pb(i);else cr.pb(i);
	sol(l,m,cl,ql);sol(m+1,r,cr,qr);
}
int main(){vc c;vq q;int m;
	scanf("%d%d",&n,&m);
	rep(i,1,n){int x;
		scanf("%d",&x);A[x]=i;
	}
	rep(i,1,n){
		scanf("%d",&B[i]);
		c.pb({0,A[B[i]],i,1});
	}
	rep(i,1,m){int op;
		scanf("%d",&op);
		if(op==1){int lx,rx,ly,ry;
			scanf("%d%d%d%d",&lx,&rx,&ly,&ry);
			q.pb({i,lx,rx,ly,ry});
		}else{int x,y;ans[i]=-1;
			scanf("%d%d",&x,&y);
			c.pb({i,A[B[x]],x,-1});
			c.pb({i,A[B[y]],y,-1});
			swap(B[x],B[y]);
			c.pb({i,A[B[x]],x,1});
			c.pb({i,A[B[y]],y,1});
		}
	}
	sol(1,n,c,q);
	rep(i,1,m)if(~ans[i])printf("%d\n",ans[i]);
}