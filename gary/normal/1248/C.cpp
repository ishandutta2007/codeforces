/*
AuThOr GaRyMr
:
1.&
2.Dp
3.long long ()
4.long long INF 
5.Dp on trees: 
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
LL dp[100000+10];
const int MOD=1e9+7;
int main(){
	int n,m;
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<2<<endl;
		return 0; 
	}
	LL res=1;
	LL sum=0;
	if(n>=2){
		sum=0;
		dp[n-1]=1;
		dp[n-2]=1;
		rl(i,n-3,1){
			sum+=dp[i+2];
			sum%=MOD;
			dp[i]=sum+1;
			dp[i]%=MOD;
		}
		rb(i,1,n-1) res+=dp[i],res%=MOD;
	}
	if(m>=2){
		n=m;
		sum=0;
		dp[n-1]=1;
		dp[n-2]=1;
		rl(i,n-3,1){
			sum+=dp[i+2];
			sum%=MOD;
			dp[i]=sum+1;
			dp[i]%=MOD;
		}
		rb(i,1,n-1) res+=dp[i],res%=MOD;
	}
	cout<<(res+res)%MOD<<endl;
	return 0;
}