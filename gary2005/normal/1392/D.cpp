/*
{

AuThOr Gwj
*/
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int n;
string s;
bool a[200000+20];
int dp[200000+20][2][4]; 
void solve(){
	R(n);
	R(s);
	rep(i,n)
	{
		if(s[i]=='L'){
			a[i]=1;
		}
		else{
			a[i]=0;
		}
	}
	int res=INF;
	rep(i,2)
		rep(j,2){
			rep(k,n)
				rep(l,2)
					rep(m,4)
						dp[k][l][m]=INF;
			if(i==j){
				dp[1][j][2]=(a[0]!=i)+(a[1]!=j);
			}
			else{
				dp[1][j][1]=(a[0]!=i)+(a[1]!=j);
			}
			rep(k,n){
				if(k>1){
					rep(l,2){
						rb(m,1,2){
							if(m==1){
								rb(m_,1,2)
									dp[k][l][m]=min(dp[k][l][m],dp[k-1][l^1][m_]+(a[k]!=l));
							}
							else{
								if(dp[k-1][l][m-1]!=INF)
								dp[k][l][m]=dp[k-1][l][m-1]+(a[k]!=l);
							}
						}
					}
				}
			}
			rb(m,1,2){
				rep(l,2){
					int ll=m;
					if(i==l){
						ll++;
						if(j==l) ll++;
					}
					if(ll<3){
						res=min(res,dp[n-1][l][m]);
//						cout<<l<<" "<<m<<" "<<dp[n-1][l][m]<<endl;
					}
				}
			}
		}
	cout<<res<<endl;
}
int main(){
	fastio;int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}