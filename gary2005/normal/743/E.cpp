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
int n;
const int MAXN=1021;
int nxt[MAXN][MAXN];
int las[8];
int a[MAXN];
int dp[MAXN][1<<8];
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d",&a[i]);
		a[i]--;
	}
	rl(i,n,1){
		rb(j,1,n){
			if(j==1) nxt[i][1]=i;
			else nxt[i][j]=nxt[las[a[i]]][j-1];
		}
		las[a[i]]=i;
	}
	int rest=0;
	rb(lim,1,n){
		memset(dp,-63,sizeof(dp));
		dp[1][0]=0;
		rb(i,1,n)
			rep(mask,1<<8){
				if(dp[i][mask]>=0){
					check_max(dp[i+1][mask],dp[i][mask]);
					if((mask>>a[i])&1);
					else{
						if(nxt[i][lim]){
							check_max(dp[nxt[i][lim]+1][mask|(1<<a[i])],dp[i][mask]+lim);
						}
						if(nxt[i][lim-1]){
							check_max(dp[nxt[i][lim-1]+1][mask|(1<<a[i])],dp[i][mask]+lim-1);
						}	
					}
				}
			}
		if(lim==1)
			rep(mask,1<<8)
				check_max(dp[n+1][(1<<8)-1],dp[n+1][mask]);
		check_max(rest,dp[n+1][(1<<8)-1]); 
	}
	cout<<rest<<endl;
	return 0;
}
/** 
  * sum[i][j]ij 
  * dp[i][mask]->dp[i'][mask']
  * 
  *
  **/