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
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1500;
typedef bitset<1500> BS;
int fa[1500],cnt[1500],siz[1500];
BS node[1500];
int n,a[1500][1500];
int root(int now){
	return fa[now]=(fa[now]==now? now:root(fa[now]));
}
void merge(int u,int v){
	if(root(u)==root(v)) return ;
	cnt[root(v)]+=cnt[root(u)];
	siz[root(v)]+=siz[root(u)]; 
	node[root(v)]|=node[root(u)];
	fa[root(u)]=root(v);
}
vector<int> g[MAXN<<1],f[MAXN<<1];
vector<BS> V;
bool bad[MAXN<<1],noans[MAXN<<1];
const int MOD=998244353;
vector<int> merge(vector<int> u,vector<int> v){
	if(u.empty()) return v;
	vector<int> ret(u.size()+v.size()-1);
	rep(i,u.size())
		rep(j,v.size())
			(ret[i+j]+=1ll*u[i]*v[j]%MOD)%=MOD;
	return ret;
}
void calc(int idx){
	if(idx<n){
		f[idx].resize(2);
		f[idx][1]=1;
		return ;
	}
	for(auto it:g[idx]){
		f[idx]=merge(f[idx],f[it]);
	}
	f[idx][1]++;
}
int main(){
	scanf("%d",&n);
	rep(i,n) rep(j,n) scanf("%d",&a[i][j]);
	vector<pair<int,mp> > e;
	rep(i,n) rep(j,i) e.PB(II(a[i][j],II(j,i)));
	sort(ALL(e));
	rep(i,n) fa[i]=i,siz[i]=1,node[i].set(i);
	rep(i,n) V.PB(node[i]);
	for(auto it:e){
		merge(it.SEC.FIR,it.SEC.SEC);
		cnt[root(it.SEC.FIR)]++;
		if(cnt[root(it.SEC.FIR)]==siz[root(it.SEC.FIR)]*(siz[root(it.SEC.FIR)]-1)/2){
			V.PB(node[root(it.SEC.FIR)]);
		}
	}
	rep(i,V.size()){
		int C=0;
		rep(j,i){
			if(!noans[j]&&!bad[j]&&(V[j]&V[i]).count()==V[j].count()){
				C+=V[j].count();
				bad[j]=true;
				g[i].PB(j);
			}
		}
		if(C!=V[i].count()&&i>=n){
			noans[i]=1;
			for(auto it:g[i]){
				bad[it]=0;
			}
		}
	}
	rep(i,V.size()) if(!noans[i]) calc(i);
	rep(i,n) cout<<f[V.size()-1][i+1]<<' ';
	return 0;
}