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
LL dis[MAXN][MAXN];
int n,m;
map<mp,int> best;
int U[MAXN*MAXN],V[MAXN*MAXN],W[MAXN*MAXN];
LL fk[MAXN];
bool ok[MAXN*MAXN];
void solve(int now){
	rb(i,1,n) fk[i]=-1e18;
	rb(i,1,n){
		if(best.find(II(i,now))!=best.end()){
			LL l=best[II(now,i)];
			rb(j,1,n){
				check_max(fk[j],l-dis[i][j]);
			}
		}
	}
	rb(i,1,m){
		ok[i]|=(dis[now][U[i]]+W[i]<=fk[V[i]]||dis[now][V[i]]+W[i]<=fk[U[i]]); 
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n) rb(j,1,n) dis[i][j]=1e18;
	rb(i,1,n) dis[i][i]=0;
	rb(i,1,m){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		U[i]=u;
		V[i]=v;
		W[i]=w;
		check_min(dis[u][v],1ll*w);
		check_min(dis[v][u],1ll*w);
	}
	int q;
	scanf("%d",&q);
	rb(i,1,q){
		int u,v,l;
		scanf("%d%d%d",&u,&v,&l);
		check_max(best[II(u,v)],l);
		check_max(best[II(v,u)],l);
	}
	rb(k,1,n) rb(i,1,n) rb(j,1,n) check_min(dis[i][j],dis[i][k]+dis[k][j]);
	rb(i,1,n) solve(i);
	int rest=0;
	rb(i,1,m) rest+=ok[i];
	cout<<rest<<endl;
	return 0;
}