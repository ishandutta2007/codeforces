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
const int MOD=998244353;
LL dp[2][505][505];//  i j  k   
LL z[505];//i 
int main(){
	fastio;
	int n,K;
	cin>>n>>K;
	dp[1][1][1]=1ll;
	int now=1,nex=0;
	rb(i,1,n-1){
		rb(j,1,n)
			rb(k,j,n){
				if(dp[now][j][k]){
					if(j==k){
						dp[nex][1][k]+=dp[now][j][k],dp[nex][1][k]%=MOD;
						dp[nex][k+1][k+1]+=dp[now][j][k],dp[nex][k+1][k+1]%=MOD;
					}
					else{
						dp[nex][1][k]+=dp[now][j][k],dp[nex][1][k]%=MOD;
						dp[nex][j+1][k]+=dp[now][j][k],dp[nex][j+1][k]%=MOD; 
					}
					
				}
			}
		rb(j,1,n)
			rb(k,1,n)
				dp[now][j][k]=0;
		swap(now,nex);
	}
		 
	rb(j,1,n)
		rb(k,1,n)
			z[k]+=dp[now][j][k],z[k]%=MOD;
	LL res=0;
	rb(i,1,n)
		rb(k,1,n)
			if(i*k<K){
				res+=z[i]*z[k];
				res%=MOD;
			}
	res<<=1;
	res%=MOD;
	cout<<res<<endl;
	return 0;
}