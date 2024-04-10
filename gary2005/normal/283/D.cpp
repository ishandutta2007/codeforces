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
const int MAXN=5005;
int n;
LL a[MAXN];
int dp[MAXN];
int lg[MAXN];
bool check(int A,int B){
	int dis=B-A;
	LL x,y;
	x=a[A],y=a[B];
	if(dis>lg[B]){
		y>>=lg[B];
		return x%y==0;
	}
	y>>=dis;
	return (x>=y&&(x-y)%(y<<1)==0);
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%lld",&a[i]);
	rb(i,1,n){
		LL tmp=a[i];
		while(!(tmp&1)){
			tmp>>=1;
			lg[i]++;
		}
	}
//	cout<<check(1,2)<<endl;
	rb(i,1,n){
		dp[i]=i-1;
		rb(j,1,i-1){
			if(check(j,i)){
				check_min(dp[i],dp[j]+i-j-1);
			}
		}
	}
	int rest=1e9;
	rb(i,1,n){
		check_min(rest,dp[i]+n-i);
	}
	cout<<rest<<endl;
	return 0;
}