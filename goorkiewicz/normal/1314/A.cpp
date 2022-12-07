#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const int N = 200005;
int n, i, j;
pair <ll,ll> t [N];
ll out;
unordered_map <ll,ll> nxt;

ll find (ll u)
	{
	if (nxt.find(u) == nxt.end())
		return u;
	nxt[u] = find(nxt[u]);
	return nxt[u];
	}

int main ()
	{
	scanf ("%d", &n);
	for (i=1; i<=n; i++) scanf ("%lld", &t[i].s);
	for (i=1; i<=n; i++) scanf ("%lld", &t[i].f);
	
	sort(t+1, t+n+1);
	reverse(t+1, t+n+1);

	for (i=1; i<=n; i++)
		{
		pair <ll,ll> p = t[i];
		
		ll i = p.s;
		ll v = p.f;
		ll j = find(i);
		
		out += 1ll * (j-i) * v;
		
		nxt[j] = j+1;
		}
	
	printf ("%lld\n", out);
	return 0;
	}