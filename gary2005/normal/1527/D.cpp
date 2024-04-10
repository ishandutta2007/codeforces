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
const int MAXN=2e5+233;
LL ans[MAXN];
int in[MAXN],out[MAXN],siz[MAXN],cnt,n;
vector<int> g[MAXN];
void dfs(int now,int pre){
	siz[now]=1;
	in[now]=++cnt;
	for(auto it:g[now]) if(it!=pre) dfs(it,now),siz[now]+=siz[it];
	out[now]=++cnt;
}
bool isfa(int u,int v){
	return in[u]<=in[v]&&out[u]>=out[v];
}
void solve(){
	cnt=0;
	scanf("%d",&n);
	rb(i,0,n) ans[i]=0;
	rb(i,0,n-1) g[i].clear();
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(0,-1);
	int A,B;
	int cona,conb;
	cona=siz[0];
	int TTmp;
	for(auto it:g[0]) if(isfa(it,1)) cona-=siz[it],TTmp=it;
	conb=siz[1];
	ans[0]=1ll*n*(n-1)/2;
	ans[1]=ans[0];
	for(auto it:g[0]) ans[1]-=1ll*siz[it]*(siz[it]-1)/2;
	ans[2]=1ll*cona*conb;
	A=0,B=1;
	rb(i,3,n){
		if(isfa(i-1,A)||isfa(i-1,B)){
			ans[i]=1ll*cona*conb;
			continue;
		}
		if(isfa(B,i-1)){
			B=i-1;
			conb=siz[B];
			ans[i]=1ll*cona*conb;
		}
		else{
			if(isfa(A,i-1)){
				if(A==0&&isfa(TTmp,i-1)) break;
				A=i-1;
				cona=siz[A];
				ans[i]=1ll*cona*conb;
			}
			else{
				break;
			}
		}
	}
	ans[n+1]=0;
	rb(i,0,n) printf("%lld ",ans[i]-ans[i+1]);puts("");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}

/*

3

4
0 3
3 1
3 2

5
0 1
1 2
2 3
3 4


4
0 3
3 1
3 2


*/