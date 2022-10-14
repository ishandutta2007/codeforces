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
int a[505];
mp ok[505][505];
int dp[505][505];
int main(){
	fastio;
	int n;
	cin>>n;
	rb(i,1,n)
		cin>>a[i],ok[i][i]=II(1,a[i]);
	rb(len,1,n)	{
		rb(i,1,n){
			int j=i+len-1;
			if(j>n) break;
			rb(k,i,j-1){
//				cout<<k<<endl;
				if(ok[i][k].FIR&&ok[k+1][j].FIR)
				if(ok[i][k].SEC==ok[k+1][j].SEC){
//					cout<<""<<endl;
					ok[i][j].FIR=1;
					ok[i][j].SEC=ok[i][k].SEC+1;
				}
			}
		}
	}
	memset(dp,0x3f,sizeof(dp));
	rb(len,1,n)
	{
		rb(i,1,n){
			int j=i+len-1;
			if(j>n) break;
			if(ok[i][j].FIR) dp[i][j]=1;
			for(int k=i;k<j;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	}
	cout<<dp[1][n]<<endl;
	return 0;
}
/*
7
2 1 1 1 1 1 2
*/