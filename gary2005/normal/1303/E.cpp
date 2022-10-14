/*
AuThOr GaRyMr
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
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
int dp[404][404];
	string S,T;
bool check(string A,string B){
	memset(dp,-0x3f,sizeof(dp));
	dp[0][0]=0;
	int L1,L2;
	L1=A.length();
	L2=B.length();
	A='%'+A;
	B='^'+B;
	A=A+'^';
	B=B+'&';
//	cout<<" "<<A<<" "<<B<<endl;
	rb(i,1,S.length()){
//		cout<<i<<"_"<<endl;
		rb(j,0,L1){
			if(dp[i-1][j]>=0) 
			dp[i][j]=max(dp[i][j],dp[i-1][j]+bool(S[i-1]==B[dp[i-1][j]+1]));
			if(S[i-1]==A[j]){
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
			}
			if(j==L1&&dp[i][j]==L2){
				return 1;
			}	
		}
	}
	return 0;
}
void solve(){
	cin>>S>>T;
	int len=T.length();
	rep(i,len){
		string s,t;
//		cin>>s>>t;
		s=t="";
		rep(j,i){
			s+=T[j];
		}
		rep(j,len)
			if(j>=i)
				t+=T[j];
		if(check(s,t)){
			cout<<"YES"<<endl;
			return; 
		} 
	}
	cout<<"NO"<<endl; 
}
int main(){
	fastio;
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}