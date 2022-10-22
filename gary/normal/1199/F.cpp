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
char A[55][55];
int dp[55][55][55][55];
int v[55][55][55][55];
int n;
int dfs(int a,int b,int c,int d){
	if(v[a][b][c][d]) return dp[a][b][c][d];
	v[a][b][c][d]=1;
	dp[a][b][c][d]=max(c-a+1,d-b+1);
	int OK=1;
	rb(i,a,c){
		rb(j,b,d){
			if(A[i][j]!='.') OK=false;
		}
	}
	if(OK){
		return dp[a][b][c][d]=0;
	}
	rb(i,a+1,c){
			dp[a][b][c][d]=min(dp[a][b][c][d],dfs(a,b,i-1,d)+dfs(i,b,c,d));
	}
	rb(i,b+1,d) dp[a][b][c][d]=min(dp[a][b][c][d],dfs(a,b,c,i-1)+dfs(a,i,c,d));
	
	return dp[a][b][c][d];
}
int main(){
	cin>>n;
	rb(i,1,n)
		rb(j,1,n) cin>>A[i][j];
	cout<<dfs(1,1,n,n)<<endl;
//	rb(i,1,n){
//		rb(j,1,n){
//			rb(k,i,n){
//				rb(l,j,n){
//					cout<<i<<","<<j<<","<<k<<","<<l<<" : "<<dp[i][j][k][l]<<":vis "<<v[i][j][k][l]<<endl;
//				}
//			}
//		}
//	}
	return 0;
}