/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=150000+23;
int n,m,k,fa[MAXN][18],depth[MAXN],dfn[MAXN],siz[MAXN],cnt=0;
vector<int> g[MAXN];
LL rest=0;
void dfs(int now,int pre){
	fa[now][0]=pre;
	dfn[now]=++cnt;
	siz[now]=1;
	rb(i,1,17) fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto it:g[now]) if(it!=pre) depth[it]=depth[now]+1,dfs(it,now),siz[now]+=siz[it];
}
int jump(int now,int dis){rep(i,18) if((dis>>i)&1) now=fa[now][i]; return now;}
int lca(int u,int v){
	if(depth[u]>depth[v]) swap(u,v);
	v=jump(v,depth[v]-depth[u]);
	if(u==v) return u;
	rl(i,17,0){	if(fa[u][i]!=fa[v][i]){u=fa[u][i],v=fa[v][i];}}
	return fa[u][0];
}
struct BIT{
	int bit[MAXN];
	BIT(){memset(bit,0,sizeof(bit));}
	void add(int pos,int val){while(pos<=n){bit[pos]+=val,pos+=pos&(-pos);}}
	int sum(int pos){int s=0;while(pos){s+=bit[pos],pos^=pos&(-pos);}return s;}
	int query(int l,int r){if(r<l) return 0;return sum(r)-sum(l-1);}
}ds1,ds2;
vector<mp> v[MAXN];
void work3(vector<int> & V,int now){
	for(auto it:V){
		if(depth[it]-depth[now]>=k){
			int z=jump(it,depth[it]-depth[now]-k);
			rest-=ds2.query(dfn[z],dfn[z]+siz[z]-1);
		}
		ds2.add(dfn[it],1);
	}
	for(auto it:V) ds2.add(dfn[it],-1);
}
vector<int> vt[MAXN];
bool cmp(int A,int B){return dfn[A]<dfn[B];}
vector<mp> va[MAXN];
int root[MAXN];
vector<mp> inf[MAXN];
struct node{
	int sum,l,r;
	node(){sum=l=r=0;}
};
node dt[MAXN*23];
int newnode(){dt[++cnt]=node();return cnt;}
void pu(int now){dt[now].sum=dt[dt[now].l].sum+dt[dt[now].r].sum;} 
const int N=1<<18;
void add(int pos,int now,int l=1,int r=N+1){
	if(l==r-1){
		dt[now].sum++;
		return ;
	}
	int mid=(l+r)>>1;
	if(mid>pos){
		if(!dt[now].l) dt[now].l=newnode();
		add(pos,dt[now].l,l,mid);
	}
	else{
		if(!dt[now].r) dt[now].r=newnode();
		add(pos,dt[now].r,mid,r);
	}
	pu(now);
}
int query(int a,int b,int now,int l=1,int r=N+1){
	if(!now) return 0; 
	if(r<=a||l>=b) return 0;
	if(r<=b&&l>=a) return dt[now].sum;
	int mid=(l+r)>>1;
	return query(a,b,dt[now].l,l,mid)+query(a,b,dt[now].r,mid,r);
}
int merge(int a,int b){
	if(!a||!b) return a+b;
	dt[a].sum+=dt[b].sum;
	dt[a].l=merge(dt[a].l,dt[b].l);
	dt[a].r=merge(dt[a].r,dt[b].r);
	return a;
}
void gao(int now,int t,int rt,int T){
	t=max(0,k-t);
	if(depth[now]-depth[rt]>=t){
		now=jump(now,depth[now]-depth[rt]-t);
//		cout<<dfn[now]<<"_"<<dfn[now]+siz[now]-1<<' '<<dfn[8]<<endl;
		rest+=query(dfn[now],dfn[now]+siz[now],T);
	}
}
void Run(int now,int s){
	for(auto it:inf[now]){
		gao(it.SEC,depth[now]-depth[s],s,root[now]);
		va[now].PB(it);
//		cout<<now<<" "<<dfn[it.SEC]<<endl;
		add(dfn[it.SEC],root[now]);
	}
	for(auto it:vt[now]){
		Run(it,s);
		if(va[it].size()>va[now].size()) swap(va[it],va[now]),swap(root[now],root[it]);
		for(auto itt:va[it]){
//			cout<<"_"<<now<<"+"<<it<<' '<<itt.FIR<<' '<<itt.SEC<<endl;
			gao(itt.SEC,depth[now]-depth[s],s,root[now]);
			va[now].PB(itt);
		}
		root[now]=merge(root[it],root[now]);
	}
}
void work2(vector<mp> & V,int now){
//	for(auto it:V){
//		cout<<":"<<it.FIR<<" "<<it.SEC<<endl;
//	}
	if(V.empty()) return ;
	vector<int> Lp,Rp;
	for(auto it:V) Lp.PB(it.FIR);
	for(auto it:V) Rp.PB(it.SEC);
	work3(Lp,now);
	work3(Rp,now);
	vector<int> No;
	for(auto it:V) No.PB(it.FIR),No.PB(it.SEC);
	sort(ALL(No),cmp);
	vector<int> vitt=No;
	rep(i,No.size()-1) vitt.PB(lca(No[i],No[i+1]));
	sort(ALL(vitt));
	vitt.erase(unique(ALL(vitt)),vitt.end());
	cnt=0;
	for(auto it:vitt) vt[it].clear();
	for(auto it:vitt) va[it].clear(),root[it]=newnode(),inf[it].clear();
	for(auto it:V) inf[it.FIR].PB(it);
	sort(ALL(vitt),cmp);
	stack<int> sta;
	sta.push(vitt[0]);
	rb(i,1,vitt.size()-1){
		while(dfn[sta.top()]+siz[sta.top()]-1<dfn[vitt[i]]||dfn[sta.top()]>dfn[vitt[i]]) sta.pop();
		vt[sta.top()].PB(vitt[i]);
		sta.push(vitt[i]);
	}
	Run(vitt[0],now);
}
void work(int now){
	map<mp,vector<mp> > M;
	for(auto it:v[now]){
		if(it.FIR!=now&&it.SEC!=now){
			mp A,B;
			A=II(jump(it.FIR,depth[it.FIR]-depth[now]-1),jump(it.SEC,depth[it.SEC]-depth[now]-1));
			B=II(it.FIR,it.SEC);
			if(dfn[A.FIR]>dfn[A.SEC]) swap(A.FIR,A.SEC),swap(B.FIR,B.SEC);
			M[A].PB(B);
		}
	}
	for(auto ite=M.begin();ite!=M.end();++ite) work2(ite->SEC,now);
}
void gao(int now,int pre){
	for(auto it:v[now]){
		int z;
		if(depth[it.SEC]-depth[now]>=k){
			z=jump(it.SEC,depth[it.SEC]-depth[now]-k);
			rest+=ds1.query(dfn[z],dfn[z]+siz[z]-1);
		}
		if(depth[it.FIR]-depth[now]>=k){
			z=jump(it.FIR,depth[it.FIR]-depth[now]-k);
			rest+=ds1.query(dfn[z],dfn[z]+siz[z]-1);
		}
		ds1.add(dfn[it.FIR],1),ds1.add(dfn[it.SEC],1);
	}
	work(now);
	for(auto it:g[now]) if(it!=pre) gao(it,now);
	for(auto it:v[now]) ds1.add(dfn[it.FIR],-1),ds1.add(dfn[it.SEC],-1);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	rb(i,1,m){
		int s,t;
		scanf("%d%d",&s,&t);
		v[lca(s,t)].PB(II(s,t));
	}
	gao(1,0);
	cout<<rest<<endl;
	return 0;
}/*

5 5 2
1 2
2 3
1 4
4 5


3 5
2 5
3 4
1 5
1 3
*/