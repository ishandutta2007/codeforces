#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11,M=N<<3;
vector<pair<int,int> >b[N];
 
int f[N],g[N];
int a[N<<1],cnt,n,m;
#define m ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
 
int ql,qr,qv,qans;
int mx[M],tg[M];
void pt(int x,int v){
	if(f[tg[x]] < f[v]) tg[x]=v;
	if(f[mx[x]] < f[v]) mx[x]=v;
}
void pu(int x){
	mx[x]=mx[ls];
	if(f[mx[rs]] > f[mx[x]]) mx[x]=mx[rs];
}
void pd(int x){
	//cerr<<x<<" pd "<<tg[x]<<endl;
	if(tg[x]){
		
		pt(ls,tg[x]);
		pt(rs,tg[x]);
		tg[x]=0;
	}
}
void qry(int x,int l,int r){
	if(ql<=l&&r<=qr) {
	//	cerr<<"qry "<<x<<" "<<l<<" "<<r<<" "<<mx[x]<<" "<<tg[x]<<endl;
		if(f[mx[x]] > f[qans]) qans=mx[x];
		return;
	}
	pd(x);
	if(ql<m)qry(ls,l,m);
	if(qr>m)qry(rs,m,r);
}
void upd(int x,int l,int r){
	
	if(ql<=l&&r<=qr){
	//	cerr <<"upd " << x << " " << l <<" "<< r<< endl;
		pt(x,qv);
		return;
	}
	pd(x);
	if(ql<m) upd(ls,l,m);
	if(qr>m) upd(rs,m,r);
	pu(x);
}
#undef m
#undef ls
#undef rs
int vis[N];
int main(){
#ifdef flukehn
	freopen("d.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		int id,l,r;
		cin>>id>>l>>r;
		b[id].push_back(make_pair(l,r));
		a[++cnt]=l;
		a[++cnt]=r;
	}
	sort(a+1,a+cnt+1);
	cnt=unique(a+1,a+cnt+1)-a;
	for(int i=1;i<=n;++i){
		int p=0;
		for(auto &w:b[i]){
			int x=lower_bound(a+1,a+cnt,w.first)-a;
			int y=lower_bound(a+1,a+cnt,w.second)-a;

			w=make_pair(x,y);
			ql=x;
			qr=y+1;
	//		cerr<<i<<" "<<ql<<" "<<qr<<endl;
			qans=0;
			qry(1,1,cnt);
			if(f[qans]>f[p])p=qans;
		}
		f[i]=f[p]+1;
		g[i]=p;
	//	cerr<<i<<" ----- "<<p<<endl; 
		for(auto w:b[i]){
			ql=w.first;
			qr=w.second+1;
	//		cerr<<i<<" "<<ql<<" "<<qr<<endl;
			qv=i;
			upd(1,1,cnt);
		}
	}
	int p=1;
	for(int i=2;i<=n;++i)if(f[i]>f[p])p=i;
	if(f[p]==n){
		puts("0");
	}else{
		while(p) vis[p]=1,p=g[p];
		vector<int> ans;
		for(int i=1;i<=n;++i)if(!vis[i])ans.push_back(i);
		int m=ans.size();
		cout<<m<<endl;
		for(int i=0;i<m;++i)cout<<ans[i]<<" \n"[i==m-1];
	}
	//cout<<p<<" "<<f[p]<<endl;
}