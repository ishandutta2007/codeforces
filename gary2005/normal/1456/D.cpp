/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
const int MAXN=5005;
bool dp[MAXN][MAXN];
LL g[MAXN];
LL t[MAXN],x[MAXN];
int n;
int main(){
	memset(g,127,sizeof(g));	
	scanf("%d",&n);
	rb(i,1,n) 	scanf("%I64d%I64d",&t[i],&x[i]);
	g[0]=0;
	rb(i,0,n-1){
		if(i==n-1&&dp[i][i+1]){
			cout<<"YES";
			return 0;
		}
		rb(j,i+2,n){
			if(t[i+1]-t[i]>=abs(x[i+1]-x[i]))
				dp[i+1][j]|=dp[i][j];
		}
		if(dp[i][i+1]&&max(t[i+1],t[i]+abs(x[i+2]-x[i]))<=t[i+2])
			check_min(g[i+2],max(t[i+1],t[i]+abs(x[i+2]-x[i])));
		if(max(t[i],g[i]+abs(x[i+1]-x[i]))<=t[i+1])
		check_min(g[i+1],max(t[i],g[i]+abs(x[i+1]-x[i])));
		if(dp[i][i+1]){
			rb(j,i+3,n){
				if(max(t[i+1],t[i]+abs(x[j]-x[i]))+abs(x[i+2]-x[j])<=t[i+2]){
					dp[i+2][j]=1;
				}
			}
		}
		rb(j,i+2,n){
			if(max(t[i],g[i]+abs(x[j]-x[i]))+abs(x[j]-x[i+1])<=t[i+1]){
				dp[i+1][j]=1;
			}
		}
	}
	puts(g[n]<=t[n]? "YES":"NO");
	return 0;
}