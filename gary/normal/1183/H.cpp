/**
 *    author:  gary
 *    created: 25.09.2021 14:44:06
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
LL n;LL k;
LL dp[101][101];
string S;
LL last[101];
map<char , LL> FIRF;
LL res=0;
LL JIAN(int i,int j){
	if(last[i]){
		return dp[last[i]-1][j-1];
	}
	else{
		return 0;
	}
}
void solve(){
	rb(i,0,100) {
		dp[i][0]=1;
	}
	rb(i,1,n){
		last[i]=FIRF[S[i-1]];
		FIRF[S[i-1]]=i;
	}
	rb(i,1,n){
		rb(j,1,n){
			dp[i][j]=dp[i-1][j]+dp[i-1][j-1]-JIAN(i,j);
		}
	}
	LL tmpk=k;
	rl(i,n,0){
		if(tmpk<=0) break;
		res+=(LL)(min(tmpk,dp[n][i]))*(n-(LL)(i));
		tmpk-=dp[n][i];
	}
	if(tmpk>0){
		res=-1;
	}
}
int main(){
	scanf("%lld %lld",&n,&k);
	cin>>S;
	solve();
	printf("%lld\n",res);
	return 0;
}