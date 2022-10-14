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
const int MAXN=606;
vector<mp> g[MAXN];
int dis[MAXN],n,m,vis[MAXN],pre[MAXN],suf[MAXN];
void work(int s){
	memset(vis,0,sizeof(vis));
	memset(dis,63,sizeof(dis));
	dis[s]=0;
	rb(T,1,n){
		int now=-1;
		rep(i,n) if(!vis[i]&&(now==-1||dis[i]<dis[now])) now=i;
		vis[now]=1;
//		cout<<now<<" "<<dis[now]<<endl;
		int tmp=dis[now]%n;
		vector<mp> tmpg;
		rep(i,n) pre[i]=suf[i]=INF;
		for(auto it:g[now]) pre[(it.FIR+tmp)%n]=it.SEC-(it.FIR+tmp)%n,suf[(it.FIR+tmp)%n]=it.SEC+n-(it.FIR+tmp)%n;
		rep(i,n) if(i) check_min(pre[i],pre[i-1]);
		rl(i,n-1,0) if(i!=n-1) check_min(suf[i],suf[i+1]);
		rep(nex,n){
			check_min(dis[nex],pre[nex]+nex+dis[now]);
			check_min(dis[nex],suf[nex]+nex+dis[now]);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		g[a].PB(II(b,c));
	}
	rep(i,n){
		work(i);
		rep(j,n) printf("%d ",dis[j]);
		puts("");
	}
	return 0;
}