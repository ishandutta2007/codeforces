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
int n,m,v[MAXN],t[MAXN];
bool dis[MAXN][2];
vector<int> g[MAXN];
bool have[2];
void solve(){
	have[0]=have[1]=0;
	scanf("%d%d",&n,&m);
	rb(i,1,n) scanf("%d",&v[i]),dis[i][0]=dis[i][1]=0,g[i].clear();
	rb(i,1,n) scanf("%d",&t[i]);
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	queue<mp> q;
	q.push(II(1,0));
	dis[1][0]=1;
	while(!q.empty()){
		mp now=q.front();
		q.pop();
		for(auto it:g[now.FIR]){
			if(!dis[it][now.SEC^1]){
				dis[it][now.SEC^1]=1;
				q.push(II(it,now.SEC^1));
			}
		}
	}
	LL sum[2]={0,0};
	rb(i,1,n){
		if(dis[i][0]&&dis[i][1]){
			assert(i==1);
			rb(j,1,n){
				sum[0]+=t[j]-v[j];
			}
			if(abs(sum[0])&1) puts("NO");
			else puts("YES");
			return ;
		}
		if(dis[i][0]) sum[0]+=t[i]-v[i];
		else sum[1]+=t[i]-v[i];
	}
	if(sum[0]==sum[1]) puts("YES");
	else puts("NO");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}