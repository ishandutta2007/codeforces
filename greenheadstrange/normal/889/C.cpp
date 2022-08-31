#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define maxn 1000005
#define mod 1000000007
using namespace std;
ll ans[maxn]; 
ll jc[maxn];	
int n, k;
int a[maxn];
int fast_max() { 
    int ans = 0;
    int offset = 0;
    for (int i = 0; i < n; ++i)
        if (ans < a[i]) {
            ans = a[i];
            offset = 0;
        } else {
            offset = offset + 1;
            if (offset == k)
                return ans;
        }
    return ans;
}
bool hv[maxn];
int nans = 0;
void dfs(int pl)
{
	if(pl == n)
	{
		if(fast_max() != n)
			nans++;
		return;
	}
	for(int i = 1; i <= n; i++)
		if(!hv[i])
			hv[i] = 1, a[pl] = i, dfs(pl + 1), hv[i] = 0;
}
ll ksm(ll a, ll k)
{
	if(!k) return 1;
	ll ns = ksm(a, k >> 1);
	ns *= ns, ns %= mod;
	if(k & 1) ns *= a, ns %= mod;
	return ns;
}
ll ted[maxn];
ll bjc[maxn];
int main() 
{
	scanf("%d%d", &n, &k);
//	dfs(0);
	jc[0] = 1;
	for(int i = 1; i <= n; i++)
		jc[i] = jc[i - 1] * (ll)i, jc[i] %= mod, bjc[i] = ksm(jc[i], mod - 2);
	for(int i = k + 1; i <= n; i++)
	{
		ted[i] = ted[i - 1] * (ll)i + jc[i - 1] - ted[i - k - 1] * (jc[i - 1] * bjc[i - k - 1] % mod);
		ted[i] %= mod;
		if(ted[i] < 0) ted[i] += mod;
		//cout<<i<<" "<<ted[i]<<endl;
	}
	for(int i = 1; i <= n; i++)
	{
		ans[i] = (ll)(i - 1) * ans[i - 1], ans[i] %= mod;
		if(i >= k + 1)
			ans[i] += ted[i - 1];
			ans[i] %= mod;
	//	cout<<i<<" "<<ans[i]<<endl;
	}
	printf("%I64d\n", ans[n]);
//	cout<<nans<<endl;
	return 0;
}