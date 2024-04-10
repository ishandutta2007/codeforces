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
const int MAXN=5e5+233;
int n;
int dp[MAXN];
int tot[MAXN];
int a[MAXN];
int is[MAXN];
int e[MAXN];
int r[MAXN];
int t[MAXN];
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		tot[a[i]]++;
		if(tot[a[i]]==1){
			is[i]=1;
		}
		t[i]=tot[a[i]];
		e[a[i]]=i;
	}
	memset(dp,63,sizeof(dp));
	dp[n+1]=0;
	rl(i,n,1){
		if(a[i]==a[i+1]){
			r[i]=r[i+1];
		}
		else{
			r[i]=i;
		}
	}
	rl(i,n,1){
		check_min(dp[i],dp[i+1]+1); 
		if(is[i]){
			check_min(dp[i],dp[e[a[i]]+1]+e[a[i]]-i+1-tot[a[i]]);
		}
		check_min(dp[i],n-i+1-(tot[a[i]]-t[i]+1));
	}
	cout<<dp[1]<<endl;
	return 0;
}
/*

11
1 2 2 2 4 2 1 1 1 4 1

*/