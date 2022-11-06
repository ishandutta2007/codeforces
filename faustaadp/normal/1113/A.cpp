#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
using namespace std;
ll n, k, d[110][110];
ll depe(ll pos, ll sisa)
{
	if(sisa < 0)
		return 1e18;
	if(pos == n)
		return 0;
	ll ret = d[pos][sisa];
	if(ret == -1)
	{
		ret = 1e18;
		if(sisa < k)
			ret = min(ret, depe(pos, sisa + 1) + pos);
		ret = min(ret, depe(pos + 1, sisa - 1));
	}
	return d[pos][sisa] = ret;
}
int main()
{
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> k;
	memset(d, -1, sizeof(d));
	cout << depe(1, 0) << "\n";
}