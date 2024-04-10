#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int mod = 998244353;

inline ll pw(ll a,int b)
{
	ll res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

int n,d,a[MAXN];
int f[MAXN][2];

inline ll solve(vector<int> &a)
{
	if(!a.size()) return 1;
	
	vector<int> b;
	for(int i=0; i<(int)a.size(); ++i)
		if(a[i]!=-1) b.push_back(i);
	
	if(!b.size()) return d * pw(d-1, a.size()-1) %mod;
	
	ll ans = pw(d-1, b[0]) * pw(d-1, a.size()-1 - b.back()) %mod;
	
	for(int i=0; i+1<(int)b.size(); ++i)
		ans = ans * f[ b[i+1]-b[i]-1 ][ a[b[i]] == a[b[i+1]] ] %mod;
	
	return ans;
}

int main(void)
{
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	f[0][1] = 0;
	f[0][0] = 1;
	for(int i=1; i<=n; ++i)
		for(int j=0; j<=1; ++j)
			f[i][j] = (pw(d-1,i) + mod - f[i-1][j]) %mod;
	
	vector<int> odd;
	for(int i=1; i<=n; i+=2)
		odd.push_back(a[i]);
	
	vector<int> even;
	for(int i=2; i<=n; i+=2)
		even.push_back(a[i]);
	
	printf("%lld",solve(odd) * solve(even) %mod);
	return 0;
}