//* AuThOr GaRyMr *//
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
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
inline void solve(){
	int dp[16][101]={0},n,m,a[5][101];
	cin>>n>>m;
	rb(i,1,n)
		rb(j,1,m) cin>>a[i][j];
	if(n<=3){
		vector<int> v;
		rb(i,1,n)
			rb(j,1,m) v.PB(-a[i][j]);
		sort(ALL(v));
		int res=0;
		rep(i,n) res-=v[i];
		cout<<res<<endl;
	}
	else{
		rb(k,1,m)
		rb(i,0,15)
			rb(j,0,15)
				if((i&j)==j){
//					cout<<i<<" "<<j<<" "<<k<<endl;
					int best1=dp[i^j][k-1],best2=-INF;
					rep(l,4){
						int tmp=0;
						rep(m_,4){
							if((j&(1<<m_))==(1<<m_)){
								tmp+=a[(l+m_)%4+1][k];
							}
						}
						best2=max(best2,tmp);
					}
//					cout<<best1<<" "<<best2<<endl;
					dp[i][k]=max(dp[i][k],best1+best2);
		}
//		cout<<dp[3][2]<<endl;
		cout<<dp[15][m]<<endl;
	}
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}