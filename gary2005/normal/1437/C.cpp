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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n,a[202],dp[202][800];
int main(){
	int q;
	cin>>q;
	while(q--){
		memset(dp,INF,sizeof(dp));
		scanf("%d",&n);
		rb(i,1,n) scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		dp[0][0]=0;
		rb(i,1,n){
			int best=INF;
			rb(t,i,700){
				check_min(best,dp[i-1][t-1]);
				dp[i][t]=best+abs(a[i]-t); 
			}
		}
		int best=INF;
		rb(t,n,700){
			check_min(best,dp[n][t]);
		}
		printf("%d\n",best);
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/