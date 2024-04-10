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
int walk[4][2]={
{0,1},
{0,-1},
{1,0},
{-1,0}
};
int n,m,k;
const int MAXN=505;
LL dp[MAXN][MAXN][11];
LL f[11];
int r[MAXN][MAXN],l[MAXN][MAXN],d[MAXN][MAXN],u[MAXN][MAXN];
bool chk(int x,int y){
	return x>=1&&x<=n&&y>=1&&y<=m;
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	if(k&1){
		rb(i,1,n){
			rb(j,1,m){
				printf("-1 ");
			}
			puts("");
		}
		return 0;
	}
	rb(i,1,n){
		rb(j,1,m-1){
			scanf("%d",&r[i][j]);
			l[i][j+1]=r[i][j];
		}
	} 
	rb(i,1,n-1){
		rb(j,1,m){
			scanf("%d",&d[i][j]);
			u[i+1][j]=d[i][j];
		}
	}
	memset(dp,127,sizeof(dp));
	rb(i,1,n) rb(j,1,m) dp[i][j][0]=0;
	k>>=1;
	rb(Z,1,k){
		rb(x,1,n){
			rb(y,1,m){
				rep(to,4){
					int nx,ny;
					nx=x+walk[to][0];
					ny=y+walk[to][1];
					if(chk(nx,ny)){
						int e;
						if(to==0) e=r[x][y];
						if(to==1) e=l[x][y];
						if(to==2) e=d[x][y];
						if(to==3) e=u[x][y];
						check_min(dp[x][y][Z],dp[nx][ny][Z-1]+e);
					} 
				}
			}
		}
	}
	rb(i,1,n){
		rb(j,1,m){
			fill(f,f+k+1,1e15);
			f[0]=0;
			rb(Z,1,k){
				rb(Z2,1,Z){
					check_min(f[Z],f[Z-Z2]+dp[i][j][Z2]);
				}
			}
			printf("%lld ",2ll*f[k]);
		}
		puts("");
	}
	return 0;
}