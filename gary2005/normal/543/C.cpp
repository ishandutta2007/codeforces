/*
AuThOr Gwj
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int n,m,dp[1<<20],a[20][20];
string s[20];
vector<mp> v[20];
int main(){
	fastio;
	R2(n,m);
	rep(i,n)
	cin>>s[i];
	rep(i,n)
		rep(j,m) R(a[i][j]);
	vector<pair<int,int> > c[26];
	rep(j,m)
	{
		rep(i,26)
			c[i].clear();
		rep(i,n)
		{
			c[s[i][j]-'a'].PB(II(a[i][j],i));
			v[j].PB(II(1<<i,a[i][j]));
		}
		rep(i,26)
			sort(ALL(c[i]));
		rep(i,26)
		{
			if(c[i].empty()) continue;
			int mask=0,cost=0;
			rep(k,c[i].size()-1){
				cost+=c[i][k].FIR;
			}
			rep(k,c[i].size()){
				mask+=1<<c[i][k].SEC;
			}
			v[j].PB(II(mask,cost));
		}
	}
	memset(dp,63,sizeof(dp));
	dp[0]=0;
	for(register int j=1;j<=m;++j){
		rep(mask,1<<n){
			for(auto it:v[j-1]){
				dp[mask|(it.FIR)]=min(dp[mask|(it.FIR)],dp[mask]+it.SEC);
			}
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	return 0;
}