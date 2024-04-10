#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n;
ll dp[1000001];
int st,en;
int q[1000001];
pair<pair<ll,ll>,ll>a[1000001];
ll ans=0;
void in(ll& x){
	char c=getchar();
	while(c<48 || c>57) c=getchar();
	x=0;
	while(c>=48 && c<=57){
		x=x*10+c-48;
		c=getchar();
	}
}
ll b,m,s,nm;
const ll sm=(1LL<<31)-1;
bool check(ll w,ll x,ll y,ll z){
	ll b=(w>>31)*(x>>31)-(y>>31)*(z>>31);
	ll m=(w>>31)*(x&sm)+(w&sm)*(x>>31)-(y>>31)*(z&sm)-(z>>31)*(y&sm);
	ll s=(w&sm)*(x&sm)-(y&sm)*(z&sm);
	if(m<0){
		nm=-m;
		b-=(nm>>31);
		s-=(nm&sm)<<31;
	}
	else{
		b+=(m>>31);
		s+=(m&sm)<<31;
	}
	return (b<0 || b==0 && s<0);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi.fi >> a[i].fi.se >> a[i].se;
	}
	sort(a+1,a+n+1);
	st=0,en=0;
	for(int i=1; i<=n ;i++){
		while(st<en && dp[q[st]]+(-a[q[st]].fi.fi)*a[i].fi.se<dp[q[st+1]]+(-a[q[st+1]].fi.fi)*a[i].fi.se) st++;
		dp[i]=dp[q[st]]+(a[i].fi.fi-a[q[st]].fi.fi)*a[i].fi.se-a[i].se;
		ans=max(ans,dp[i]);
		if(dp[i]<=dp[q[en]]) continue;
		while(st<en && check(dp[q[en]]-dp[q[en-1]],a[i].fi.fi-a[q[en]].fi.fi,dp[i]-dp[q[en]],a[q[en]].fi.fi-a[q[en-1]].fi.fi)) en--;
		q[++en]=i;
	}
	cout << (long long)ans << endl;
	
}