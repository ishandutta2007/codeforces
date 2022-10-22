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
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[100000+10][2]/**/;
int a[100000+10]; 
int n;
int main(){
	dp[0][1]=INF;
	cin>>n;
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n){
		LL becom_minus,becom_postive;
		becom_minus=abs(a[i]+1);
		becom_postive=abs(a[i]-1);
		dp[i][0]=min(dp[i-1][0]+becom_postive,dp[i-1][1]+becom_minus);
		dp[i][1]=min(dp[i-1][1]+becom_postive,dp[i-1][0]+becom_minus);
	} 
	cout<<dp[n][0]<<endl;
	return 0;
}