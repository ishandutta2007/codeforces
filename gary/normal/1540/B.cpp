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
const int MAXN=202;
int n;
const int MOD=1e9+7;
int dis[MAXN][MAXN];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*tmp*A%MOD;
	return tmp;
}
int dp[MAXN][MAXN];
int main(){
	scanf("%d",&n);
	memset(dis,63,sizeof(dis));
	rb(i,1,n) dis[i][i]=0;
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		dis[u][v]=dis[v][u]=1;
	}
	rb(i,1,n) dp[0][i]=1;
	rb(i,1,n) dp[i][0]=0;
	int iv2=quick(2,MOD-2);
	rb(i,1,n) rb(j,1,n){
		dp[i][j]=1ll*(dp[i-1][j]+dp[i][j-1])*iv2%MOD;
	}
	rb(x,1,n)
		rb(i,1,n)
			rb(j,1,n){
				check_min(dis[i][j],dis[i][x]+dis[x][j]);
			}
	int ans=0;
	int iv=quick(n,MOD-2);
	rb(i,1,n)
		rb(j,i+1,n){
			rb(k,1,n){
				int yy=(dis[k][i]+dis[k][j]-dis[i][j])/2;
				(ans+=1ll*iv*dp[dis[k][j]-yy][dis[i][j]-(dis[k][j]-yy)]%MOD)%=MOD;
			}
		}
	cout<<ans<<endl;
	return 0;
}