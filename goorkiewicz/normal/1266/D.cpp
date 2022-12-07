#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 100005;
int n, m, i, a, b;
ll c;
ll bil [N];
vector <int> A, B;
vector < pair < pair <int,int> , ll > > out;

int main ()
	{
	scanf ("%d%d", &n, &m);
	
	while (m--)
		{
		scanf ("%d%d%lld", &a, &b, &c);
		bil[a] += c;
		bil[b] -= c;
		}
	
	for (i=1; i<=n; i++)
		{
		if (bil[i] > 0) A.push_back(i);
		if (bil[i] < 0) B.push_back(i);
		}

	while (!A.empty() || !B.empty())
		{
		a = A.back();
		b = B.back();
		
		c = min(bil[a], -bil[b]);
		
		bil[a] -= c;
		bil[b] += c;
		
		out.push_back({{a, b}, c});
		
		if (bil[a] == 0) A.pop_back();
		if (bil[b] == 0) B.pop_back();
		}
	
	printf ("%d\n", (int)(out.size()));
	for (pair < pair <int,int> , ll> p : out)
		printf ("%d %d %lld\n", p.first.first, p.first.second, p.second);
	return 0;
	}