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
//#define int double
#define fastio ios::sync_with_stdio(false)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
double r,s,p;
int a,b,c; 
double dp[200][201][201];
int main(){
	fastio;
	cin>>a>>b>>c;
	dp[a][b][c]=1.0;
	rl(i,a,0)
		rl(j,b,0)
			rl(k,c,0){
				if(!i&&!j&&!k) break;
				if(i&&!j&&!k){
					r+=dp[i][j][k];
				}
				if(!i&&j&&!k){
					s+=dp[i][j][k];
				}
				if(!i&&!j&&k){
					p+=dp[i][j][k];
				}
				double rs,rp,sp;
				rs=i*j;
				rp=i*k;
				sp=j*k;
				if(rp) dp[i-1][j][k]+=dp[i][j][k]*rp/(rp+sp+rs);
				if(rs) dp[i][j-1][k]+=dp[i][j][k]*rs/(rp+rs+sp);
				if(sp) dp[i][j][k-1]+=dp[i][j][k]*sp/(rp+rs+sp);
			}
	printf("%.10f %.10f %.10f",r,s,p);
	return 0;
}