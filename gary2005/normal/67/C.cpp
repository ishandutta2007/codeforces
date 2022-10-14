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
int ti,td,tr,te;
string a,b;
int n,m;
int dp[5005][5005];
int prea[5005][26];
int preb[5005][26];
int main(){
	cin>>ti>>td>>tr>>te;
	int pos[26]={0};
	cin>>a>>b;
	n=a.length();
	a='$'+a;
	m=b.length();
	b='*'+b;
	rb(i,1,n){
		rep(j,26) prea[i][j]=pos[j];
		pos[a[i]-'a']=i;
	}
	memset(pos,0,sizeof(pos));
	rb(i,1,m){
		rep(j,26) preb[i][j]=pos[j];
		pos[b[i]-'a']=i;
	}
	memset(dp,63,sizeof(dp));
	dp[0][0]=0;
	rb(i,0,n) rb(j,0,m) if(dp[i][j]!=INF){
		if(preb[j][a[i]-'a']&&prea[i][b[j]-'a']) check_min(dp[i][j],dp[prea[i][b[j]-'a']-1][preb[j][a[i]-'a']-1]+te+ti*(j-preb[j][a[i]-'a']-1)+td*(i-prea[i][b[j]-'a']-1));
		check_min(dp[i+1][j],dp[i][j]+td);
		check_min(dp[i][j+1],dp[i][j]+ti);
		if(i!=n&&j!=m)
		check_min(dp[i+1][j+1],dp[i][j]+(a[i+1]!=b[j+1])*tr);
	}
	cout<<dp[n][m]<<endl;
	return 0;
}