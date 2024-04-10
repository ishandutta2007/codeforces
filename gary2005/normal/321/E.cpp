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
int n,k;
int sum[4005][4005];
int dp[4005][808];
int val[4005][4005];
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
int calc(int x,int y){
	return sum[y][y]+sum[x-1][x-1]-sum[y][x-1]-sum[x-1][y];
}
void work(int j,int l,int r,int l1,int r1){
	if(l>=r) return;
	int best=-1;
	int mid=(l+r)>>1;
	rb(k,l1,min(r1,mid-1)){
		if(best==-1||dp[k][j-1]+val[k+1][mid]<dp[best][j-1]+val[best+1][mid]) {
			best=k;
		}
	}
	assert(best!=-1);
	dp[mid][j]=dp[best][j-1]+val[best+1][mid];
	if(l==r-1) return;
	work(j,l,mid,l1,best);
	work(j,mid,r,best,r1);
}
int main(){
	n=read();
	k=read();
	rb(i,1,n)
		rb(j,1,n){
			sum[i][j]=read();
		}
	rb(i,1,n)
		rb(j,1,n)
			sum[i][j]+=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
	rb(i,1,n)
		rb(j,i,n)
			val[i][j]=calc(i,j)/2;
	rep(i,n+1)
		rep(j,k+1)
			dp[i][j]=1e9+7e8;
	dp[0][0]=0;
	rb(j,1,k){
		work(j,1,n+1,0,n);
	}
	cout<<dp[n][k]<<endl; 
	return 0;
}
/*


*/