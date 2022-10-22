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
int dp[8192+1][12][2],biggest[8192+1][2];
int n,m,a[2001][2001];
void solve(){
	vector<mp > v_;
	memset(dp,0,sizeof(dp));
	memset(biggest,0,sizeof(biggest));
	cin>>n>>m;
	rb(i,1,n)
		rb(j,1,m) scanf("%d",&a[i][j]);
	rb(j,1,m){
		int mxi=-1;
		rb(i,1,n) mxi=max(mxi,a[i][j]);
		v_.PB(II(-mxi,j));
	}
	int upp=1<<n;
	upp<<=1;
	int res=0;
	int las,now;
	las=0,now=1;
	sort(ALL(v_));
	rep(it,min(m,n)){
//		cout<<"s"<<endl;
		int col=v_[it].SEC;
		rep(mov_,n){
			rep(mask,upp){
				dp[mask][mov_][now]=dp[mask][mov_][las];
				rep(now_,n){
					if(mask&(1<<now_)){
						int old_mask=mask^(1<<now_),best1=-INF;
						best1=biggest[old_mask][las];
						dp[mask][mov_][now]=max(dp[mask][mov_][now],max(best1,dp[old_mask][mov_][now])+a[now_+mov_+1-((now_+mov_+1>n)? n:0)][col]);
					}
				}
				biggest[mask][now]=max(biggest[mask][now],dp[mask][mov_][now]);
			}
		}
		swap(now,las);
	}
//	cout<<dp[1][0][2]<<endl;
	rep(mov_,n) res=max(res,dp[upp-1][mov_][las]);
	cout<<res<<endl;
}
int main(){
	int t;
	cin>>t;
	while(t--) solve();
	return 0;
}