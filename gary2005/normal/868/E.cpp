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
const int MAXN=55;
int n,s,m;
vector<mp> g[MAXN];
int dp[MAXN][MAXN],f[MAXN],depth[MAXN],cnt[MAXN];
vector<int> leaves;
void getleaf(int now,int pre){
	int cnt=0;
	for(auto it:g[now]) if(it.FIR!=pre){
		++cnt;
		getleaf(it.FIR,now);
	}
	if(cnt==0) leaves.PB(now);
}
void getdepth(int now,int pre){
	for(auto it:g[now]) if(it.FIR!=pre){
		depth[it.FIR]=depth[now]+it.SEC;
		getdepth(it.FIR,now);
	}
}
void work(int root,int thi){
	leaves.clear();
	getleaf(root,0);
	depth[root]=0;
	getdepth(root,0);
	memset(f,-63,sizeof(f));
	f[0]=INF;
	rb(i,1,leaves.size()){
		rl(k,thi,1){
			rb(j,0,k){
				if(f[k-j]>=0&&j){
					check_max(f[k],min(f[k-j],dp[leaves[i-1]][thi-j]+depth[leaves[i-1]]));
				}
			}
		}
	}
	dp[root][thi]=f[thi];
}
void gao(int now,int pre){
	for(auto it:g[now]){
		if(it.FIR!=pre){
			gao(it.FIR,now);
			cnt[now]+=cnt[it.FIR];
		}
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].PB(II(v,w));
		g[v].PB(II(u,w));
	}
	scanf("%d%d",&s,&m);
	rb(i,1,m){
		int xi;
		scanf("%d",&xi);
		cnt[xi]++;
	}
	gao(s,0);
	memset(dp,63,sizeof(dp));
	rb(i,1,n) dp[i][0]=0;
	rb(j,1,m) rb(i,1,n) work(i,j);
	int rest=INF;
	for(auto it:g[s]){
		leaves.clear();
		getleaf(it.FIR,s);
		memset(f,-63,sizeof(f));
		depth[it.FIR]=it.SEC;
		getdepth(it.FIR,s);
		f[0]=INF;
		rb(i,1,leaves.size()){
			rl(k,cnt[it.FIR],1){
				rb(j,0,k){
					if(f[k-j]>=0&&j){
						check_max(f[k],min(f[k-j],dp[leaves[i-1]][m-j]+depth[leaves[i-1]]));
					}
				}
			}
		}
		check_min(rest,f[cnt[it.FIR]]);
	}
	cout<<rest<<endl;
	return 0;
}