//by yjz
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
const int maxn = 900111;
int n, k;
bool a[11];
int b[maxn], db[maxn], inv[maxn];
int main()
{
	inv[1] = 1;
	for (int i=2; i<maxn; i++) inv[i] = mod-1ll*(mod/i)*inv[mod%i]%mod;
	cin>>n>>k;
	n /= 2;
	int mn = 10;
	vector<int> v;
	for (int i=0; i<k; i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
		mn = min(mn, x);
	}
	for (auto x:v) a[x-mn] = 1;
	b[0] = 1;
	ll ans = 0;
	for (int i=0; i<=n*9; i++)
	{
		ll sum = 0;
		for (int j=1; j<10&&j<=i; j++) sum -= a[j]?db[i-j]:0;
		for (int j=0; j<10&&j<=i; j++) sum += a[j+1]?1ll*b[i-j]*(j+1)*n:0;
		b[i+1] = sum%mod*inv[i+1]%mod;
		db[i] = 1ll*b[i+1]*(i+1)%mod;
		ans = (ans+1ll*b[i]*b[i])%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}