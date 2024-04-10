//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<LL,LL> mp;
typedef pair<mp,mp> superpair;
/*
dp2[i]->i
dp[i][0]->i 
dp[i][1]->i 
for(i:from 1 to n)
	putcost->max( dp[i-1][0].FIR+v[i]*((dp[i-1][0].SEC==c[i])? a:b) , dp[i-1][1].FIR+v[i]*((dp[i-1][1].SEC==c[i])? a:b) ,
	dp2[c[i]]+v[i]*a )
	dp2[c[i]]=max(dp2[c[i]],putcost)
	if c[i]=dp[i-1][0].SEC && putcost>dp[i-1][0].FIR 
	then dp[i][0].FIR=putcost
	
	if c[i]=dp[i-1][1].SEC && putcost>dp[i-1][1].FIR 
	then dp[i][1].FIR=putcost
	
	else if(putcost>dp[i-1][1].FIR)
	then dp[i][1]={putcost,c[i]}
	
	keep dp[i] in order
*/
int n,q;
LL c[100000+10];
mp/*value - color*/ dp[100000+10][2];//maxi,second maxi
LL dp2[100000+10];
LL v[100000+10];
void solve(){
	LL a,b;
	scanf("%I64d %I64d",&a,&b);
	memset(dp2,-127,sizeof(dp2));
	//same cost- different cost
	dp[0][0]=dp[0][1]=dp[0][2]=dp[0][3]=II((LL)(0),(LL)(0));
	rb(i,1,n){
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		LL putcost=max(dp[i-1][0].FIR+v[i]*((dp[i-1][0].SEC==c[i])? a:b),max(dp[i-1][1].FIR+v[i]*((dp[i-1][1].SEC==c[i])? a:b),dp2[c[i]]+v[i]*a));
		dp2[c[i]]=max(dp2[c[i]],putcost);
		if(c[i]==dp[i][0].SEC&&putcost>dp[i][0].FIR) dp[i][0].FIR=putcost;
		else if(c[i]!=dp[i][0].SEC&&c[i]==dp[i][1].SEC&&putcost>dp[i][1].FIR) dp[i][1].FIR=putcost;
		else if(c[i]!=dp[i][0].SEC&&c[i]!=dp[i][1].SEC&&putcost>dp[i][1].FIR) dp[i][1]=II(putcost,c[i]);
		if(dp[i][1].FIR>dp[i][0].FIR) swap(dp[i][1],dp[i][0]);
	}
	printf("%I64d\n",dp[n][0].FIR);
}
int main(){
	cin>>n>>q;
	rb(i,1,n) scanf("%I64d",&v[i]);
	rb(i,1,n) scanf("%I64d",&c[i]);
	while(q--){
		solve();
	}
	return 0;
}
/*
5 1
1 1 1 1 1
1 2 3 4 5
1 1
*/