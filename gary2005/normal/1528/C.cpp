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
const int MAXN=3e5+233;
int n;
vector<int> g[MAXN],g2[MAXN];
int in[MAXN],out[MAXN];
int cnt;
void dfs(int now,int pre){
	in[now]=++cnt;
	for(auto it:g2[now]){
		if(it==pre) continue;
		dfs(it,now);
	}
	out[now]=++cnt;
}
int ans=0;
set<mp> s;
void dfs2(int now,int pre){
	mp tho=II(-1,-1),add=II(-1,-1);
	auto ite=s.lower_bound(II(in[now],out[now]));
	if(ite!=s.end()&&ite->SEC<out[now]);
	else{
		if(ite!=s.begin()){
			ite--;
			if(ite->SEC>out[now]){
				tho=*ite;
				s.erase(ite);
			}
		}
		add=II(in[now],out[now]);
		s.insert(add);
	}
	check_max(ans,int(s.size()));
	for(auto it:g[now]){
		if(it!=pre) dfs2(it,now);
	}
	if(tho.FIR!=-1) s.insert(tho);
	if(add.FIR!=-1) s.erase(add);
}
void solve(){
	s.clear();
	ans=0;
	cnt=0;
	scanf("%d",&n);
	rb(i,1,n) g[i].clear(),g2[i].clear();
	rb(i,2,n){
		int a;
		scanf("%d",&a);
		g[a].PB(i);
		g[i].PB(a);
	}
	rb(i,2,n){
		int a;
		scanf("%d",&a);
		g2[a].PB(i);
		g2[i].PB(a);
	}
	dfs(1,0);
	dfs2(1,0);
	printf("%d\n",ans);
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}