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
const int MOD=998244353;
int pw2[300000+20];
int quick(int A,int B){
	if(B==0) return 1;
	int tmp=quick(A,B>>1);
	tmp=1ll*tmp*tmp%MOD;
	if(B&1) tmp=1ll*A*tmp%MOD;
	return tmp;
}
int dp[300000+20][2];
int C[300000+20][2];
signed main(){
	vector<vector<char> > v;
	int n,m;
	pw2[0]=1;
	rb(i,1,300000)
		pw2[i]=(pw2[i-1]<<1)%MOD;
	scanf("%d%d",&n,&m);
	v.resize(n);
	int cnt=0;
	rep(i,n){
		v[i].resize(m);
		rep(j,m){
			cin>>v[i][j];
			cnt+=(v[i][j]=='o');
		}
	}
	C[0][0]=1;
	dp[0][0]=0;
	rb(i,1,300001){
		rep(j,2){
			if(!j){
				C[i][0]=C[i-1][1];
				dp[i][0]=dp[i-1][1]+C[i-1][1];
				dp[i][0]%=MOD;
				(C[i][j]+=C[i-1][j])%=MOD;
				(dp[i][j]+=dp[i-1][j])%=MOD;
			}
			(C[i][j]+=C[i-1][j^1])%=MOD;
			(dp[i][j]+=dp[i-1][j^1])%=MOD;
		}
		dp[i-1][1]+=C[i-1][1];
		dp[i-1][1]%=MOD;
		dp[i-1][1]+=dp[i-1][0];
		dp[i-1][1]%=MOD;
	}
	int rest=0;
	rep(i,n){
		rep(j,m){
			if(v[i][j]!='o') continue;
			int k=j;
			for(k=j;k<m&&v[i][k]=='o';++k);
			(rest+=1ll*dp[k-j][1]*pw2[cnt-(k-j)]%MOD)%=MOD;
			j=k;
		}
	}
	rep(j,m){
		rep(i,n){
			if(v[i][j]!='o') continue;
			int k=i;
			for(k=i;k<n&&v[k][j]=='o';++k);
			(rest+=1ll*dp[k-i][1]*pw2[cnt-(k-i)]%MOD)%=MOD;
			i=k;
		}
	}
	rest=1ll*pw2[cnt]*cnt%MOD+MOD-rest;
	rest%=MOD;
	rest=1ll*rest*quick(2,MOD-2)%MOD;
	cout<<rest<<endl;
	return 0;
}