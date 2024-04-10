/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
#define R(a) a=read()
#define R2(a,b) a=read(),b=read()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;

/*}
*/
int n;
const int MAXN=1e5+20;
struct DSU{
	int fa[MAXN],l[MAXN],r[MAXN];
	void init(){
		rb(i,1,n) l[i]=INF,r[i]=-INF,fa[i]=i;	
	}
	int root(int x){
		return fa[x]=(fa[x]==x? x:root(fa[x]));
	}
	void merge(int u,int v){
		u=root(u);
		v=root(v);
		fa[u]=v;
		check_min(l[v],l[u]);
		check_max(r[v],r[u]);
	}
	void Set(int id,int ll_,int rr_){
		id=root(id);
		check_min(l[id],ll_);
		check_max(r[id],rr_);
	}
	bool query(int x,int y){
		if(root(x)==root(y)) return true;
		x=root(x);
		y=root(y);
		if((l[x]>=l[y]&&r[x]<=r[y])&&(l[x]>l[y]||r[x]<r[y])) return true;
		return false;
	}
}dsu;
const int N=1<<18;
struct SEGMENT_TREE{
	vector<int> node[N+N];
	void add_seg(int a,int b,int id,int now=1,int l=1,int r=N+1){
		if(r<=a||l>=b) return;
		if(r<=b&&l>=a){
			node[now].PB(id);return;
		}
		int mid=(l+r)>>1;
		add_seg(a,b,id,now<<1,l,mid);
		add_seg(a,b,id,now<<1|1,mid,r);
	}
	void process(int id,int merge_to){
		id+=N-1;
		while(id){
			for(auto it:node[id]){
				dsu.merge(it,merge_to);
			}
			node[id].clear();
			id>>=1;
		}	
	}
	void add_a_new_segment(int id){
		id=dsu.root(id); 
		add_seg(dsu.l[id]+1,dsu.r[id],id);
	}
}sgt;
map<int,int> M;
int t[MAXN],a[MAXN],b[MAXN];
int main(){
	cin>>n;
	int cnt=0;
	rb(i,1,n) 
	{
		cin>>t[i]>>a[i]>>b[i];
//		R(t[i]),R2(a[i],b[i]);
		if(t[i]==1)M[a[i]]=M[b[i]]=true;
//		cnt+=(t[i]==1);
		if(t[i]==1) assert(a[i]<=b[i]);
//		if(t[i]==1&&cnt==20){
//			cout<<a[i]<<"-----------------------"<<b[i]<<endl;
//		} 
	}
	cnt=0; 
//	if(n==100) rb(i,50,100) cout<<t[i]<<' '<<a[i]<<' '<<b[i]<<endl;
	dsu.init();
	for(auto ite=M.begin();ite!=M.end();ite++) ite->SEC=++cnt;
//	cout<<cnt<<endl;
	rb(i,1,n)
		if(t[i]==1) a[i]=M[a[i]],b[i]=M[b[i]];
	cnt=0;
	int cntq=0;
	rb(i,1,n)
	{
		int ty;
		ty=t[i];
		int x,y;
		x=a[i],y=b[i];
		if(ty==1){
			++cnt;
			if(x<y-1)
			{
				sgt.process(y,cnt);
				sgt.process(x,cnt);
			}
			dsu.Set(cnt,x,y);
//			cout<<cnt<<' '<<x<<' '<<y<<' '<<dsu.root(cnt)<<' '<<dsu.l[dsu.root(cnt)]<<' '<<dsu.r[dsu.root(cnt)]<<','<<dsu.root(20)<<' '<<dsu.root(17)<<endl;
			if(x<y-1)
			sgt.add_a_new_segment(cnt);
		}
		else{
//			cerr<<"#:"<<++cntq<<' '<<x<<','<<y<<' '<<dsu.root(x)<<' '<<dsu.root(y)<<' '<<dsu.l[dsu.root(x)]<<' '<<dsu.r[dsu.root(x)]<<' '<<dsu.l[dsu.root(y)]<<' '<<dsu.r[dsu.root(y)]<<" ";
			if(dsu.query(x,y)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/