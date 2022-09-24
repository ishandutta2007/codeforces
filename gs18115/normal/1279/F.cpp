#include<iostream>
#include<vector>
#include<algorithm>
#define ep emplace
#define eb emplace_back
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define semicolon 
#define ryan bear
using namespace std;
typedef long long ll;
typedef pair<int,int>pi;
typedef pair<ll,ll>pl;
const int inf=1e9+7;
const ll INF=1e18;
ll n,k,l;
ll solve(string s)
{
	ll all=0;
	ll i;
	vector<ll>v(n,0);
	for(i=0;i<n;i++)
		all+=(v[i]=s[i]>='a'?n*l*2:0);
	vector<ll>d(n,0);
	for(i=0;i<l;i++)
		d[0]+=v[i];
	for(i=0;i++<n-l;)
		d[i]=d[i-1]+v[i+l-1]-v[i-1];
	ll ss=0;
	ll ee=l*n*2;
	while(ss<ee)
	{
		ll m=ss+ee>>1;
		vector<pl>dp(n+1,pl(0,0));
		for(i=0;i<n;i++)
		{
			if(i<=n-l)
				dp[i+l]=max(dp[i+l],pl(dp[i].fi+d[i],dp[i].se-1));
			dp[i+1]=max(pl(dp[i].fi+m,dp[i].se),dp[i+1]);
		}
		if(-dp[n].se<=k)
			ee=m;
		else
			ss=m+1;
	}
	vector<pl>dp(n+1,pl(0,0));
	ll m=ss;
	for(i=0;i<n;i++)
	{
		if(i<=n-l)
			dp[i+l]=max(dp[i+l],pl(dp[i].fi+d[i],dp[i].se-1));
		dp[i+1]=max(pl(dp[i].fi+m,dp[i].se),dp[i+1]);
	}
	ll t=-dp[n].se;
	ll ans=all-(dp[n].fi-(n+dp[n].se*l)*m);
	return ans/n/l/2-(k+dp[n].se)*m/(n*2);
}
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
	cin>>n>>k>>l;
	if((ll)k*l>=n)
		return cout<<0<<endl,0;
	cin>>s;
	ll ans=solve(s);
	for(int i=0;i<n;i++)
		s[i]=s[i]>='a'?'A':'a';
	cout<<min(solve(s),ans);
    return 0;
}