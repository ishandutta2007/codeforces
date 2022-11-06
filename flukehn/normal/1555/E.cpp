#include<bits/stdc++.h>
using namespace std;
const int N=1e6+11,M=N*4;
struct P{
	int l,r,w;
	bool operator<(const P&t)const{
		return w<t.w;
	}
} e[300011];
#define m ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
int mn[M],tg[M];
int ql,qr,qv;
void pt(int x,int v){
	tg[x]+=v;
	mn[x]+=v;
}
void pd(int x){
	if(tg[x]){
		pt(ls,tg[x]);
		pt(rs,tg[x]);
		tg[x]=0;
	}
}
void pu(int x){
	mn[x]=min(mn[ls],mn[rs]);
}
void add(int x,int l,int r){
	//cerr<<ql<<" "<<qr<<" "<<l<<" "<<r<<" "<<m<<endl;
	if(ql<=l&&r<=qr){
		pt(x,qv);	
		return;
	}
	pd(x);
	if(ql<m)add(ls,l,m);
	if(qr>m)add(rs,m,r);
	pu(x);
}
#undef m
#undef ls
#undef rs
int n,m;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	swap(n,m);
	for(int i=1;i<=m;++i){
		int l,r,w;
		cin>>l>>r>>w;
		e[i]=(P){l,r,w};
	}
	sort(e+1,e+m+1);
	int i;
	for(i=1;i<=m;++i){
		ql=e[i].l;
		qr=e[i].r;
		qv=1;
		add(1,1,n);
		if(mn[1]>0)break;
	}
	int ii=i;
	int ans=e[i].w-e[1].w;
	int l=1;
	for(;i<=m;++i){
		if(i>ii){
			ql=e[i].l;
			qr=e[i].r;
			qv=1;
			add(1,1,n);
		}
		for(;l<i;++l){
			ql=e[l].l;
			qr=e[l].r;
			qv=-1;
			add(1,1,n);
			if(mn[1]<=0){
				qv=1;
				add(1,1,n);
				break;
			}
		}
		ans=min(ans,e[i].w-e[l].w);
	}
	cout<<ans<<endl;
}