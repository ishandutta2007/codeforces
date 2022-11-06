#include<bits/stdc++.h>
using namespace std;
const int N=120011;
typedef long long L;
int n,num[N],m;
struct Query{
	int l,r,i;
	bool operator<(const Query&t)const{return r<t.r;}
} q[N];
int s1[N],s2[N],t1,t2;
//seg
typedef pair<int,int> pa;
const int M=N<<2;
pa t[M],g[M];
L su[M];
int ad[M];
int lx,rx,px;
#define m (l+r>>1)
#define ls x*2,l,m
#define rs x*2+1,m+1,r
#define fi first
#define se second
pa merge(pa x,pa y){
	if(!x.se)return y;
	if(!y.se)return x;
	if(x.fi==y.fi)return pa(x.fi,x.se+y.se);
	return x<y?x:y;
}
void push_up(int x){
	t[x]=merge(t[x*2],t[x*2+1]);
	su[x]=su[x*2]+su[x*2+1];
}
void push_down(int x){
	if(g[x].se){
		int a=x*2,b=a+1,&c=ad[x];
		if(t[a].fi+g[x].fi<1)su[a]+=(L)t[a].se*g[x].se;
		if(t[b].fi+g[x].fi<1)su[b]+=(L)t[b].se*g[x].se;
		t[a].fi+=c,t[b].fi+=c;
		g[a]=merge(g[a],pa(g[x].fi+ad[a],g[x].se));
		g[b]=merge(g[b],pa(g[x].fi+ad[b],g[x].se));
		ad[a]+=c,ad[b]+=c;
		c=0,g[x]=pa(0,0);
	}
}
void build(int x,int l,int r){
	if(l==r){t[x]=pa(l,1);return;}
	build(ls),build(rs);
	push_up(x);
}
void update(int x,int l,int r){
	if(lx<=l&&r<=rx){
		t[x].fi+=px;
		ad[x]+=px;
		if(t[x].fi<1)su[x]+=t[x].se;//cerr<<"ok "<<x<<endl;
		g[x]=merge(g[x],pa(ad[x],1));
		return;
	}
	push_down(x);
	if(lx<=m)update(ls);
	if(rx>m)update(rs);
	push_up(x);
}
L query(int x,int l,int r){
	if(lx<=l&&r<=rx){return su[x];}
	push_down(x);
	L res=0;
	if(lx<=m)res=query(ls);
	if(rx>m)res+=query(rs);
	return res;
}
#undef m
L ans[N];
int main(){
#ifdef flukehn
	freopen("sample1.in","r",stdin);
#endif
	cin>>n;
	int i;
	for(i=1;i<=n;++i)scanf("%d",num+i);
	cin>>m;
	for(i=1;i<=m;++i)scanf("%d%d",&q[i].l,&q[i].r),q[i].i=i;
	sort(q+1,q+m+1);
//	cerr<<"ok\n";
	build(1,1,n);
	int p=1;
	for(i=1;i<=n;++i){
		//cerr<<i<<endl;
		for(;t1&&num[s1[t1]]<num[i];--t1){
			lx=s1[t1-1]+1;
			rx=s1[t1];
			px=num[i]-num[s1[t1]];
			update(1,1,n);
		}
		//cerr<<i<<endl;
		s1[++t1]=i;
		for(;t2&&num[s2[t2]]>num[i];--t2){
			lx=s2[t2-1]+1;
			rx=s2[t2];
			px=num[s2[t2]]-num[i];
			update(1,1,n);
		}
		s2[++t2]=i;
		//cerr<<i<<endl;
		lx=1,rx=n,px=-1;
		update(1,1,n);
		//if(i==1)cerr<<"t "<<t[1].fi<<" "<<t[1].se<<endl;
		//cerr<<i<<endl;
		for(;p<=m&&q[p].r<=i;++p){
			lx=q[p].l,rx=q[p].r;
			ans[q[p].i]=query(1,1,n);
		}
	//	cerr<<su[1]<<" \n"[i==n];
	}
	for(i=1;i<=m;++i)printf("%lld\n",ans[i]);
}