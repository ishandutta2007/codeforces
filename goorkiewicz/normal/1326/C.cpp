#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define f first
#define s second

const ll mod = 998244353;
const int N = 1000005;
int n, i, j, k;
int t [N];
ll out, res;
vector <ll> vec;

int main ()
	{
	scanf ("%d%d", &n, &k);
	for (i=1; i<=n; i++)
		scanf ("%d", &t[i]);
	
	for (i=1; i<=n; i++)
		if (t[i] > n-k)
			{
			res += t[i];
			vec.push_back(i);
			}
	
	assert(vec.size() == k);
	
	out = 1;
	for (i=0; i+1<vec.size(); i++)
		(out *= (vec[i+1] - vec[i])) %= mod;
	
	printf ("%lld %lld\n", res, out);
	return 0;
	}