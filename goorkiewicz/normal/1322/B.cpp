#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef const int cint;

int out [50];
vector <int> vec, a, b;

ll count (cint& v, const vector <int>& a, const vector <int>& b)
	{
	ll res = 0;
	int i, j;
	j = b.size();
	for (i=0; i<a.size(); i++)
		{
		while (j > 0 && b[j-1] + a[i] >= v)
			j--;
		res += b.size() - j;
		}
	return res;
	}

int solve (int k)
	{
	a.clear();
	b.clear();
	
	for (int& x : vec)
		(((x>>k)&1) ? a : b).push_back(x);
	
	for (int& x : a) x %= (1<<k);
	for (int& x : b) x %= (1<<k);

//	printf ("a: ");
//	for (int x : a)
//		printf ("%d ", x);
//	printf ("\n");
//	printf ("b: ");
//	for (int x : b)
//		printf ("%d ", x);
//	printf ("\n");
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	ll res = 1ll * a.size() * b.size() - count((1<<k), a, b);
	
	ll cnt1 = count((1<<k), a, a);
	ll cnt2 = count((1<<k), b, b);

	for (cint& x : a) if (x + x >= (1<<k)) cnt1--;
	for (cint& x : b) if (x + x >= (1<<k)) cnt2--;
	
	assert(cnt1%2 == 0);
	assert(cnt2%2 == 0);
	
	cnt1 /= 2;
	cnt2 /= 2;

	res += cnt1 + cnt2;
	
	return (res%2);
	}

int main ()
	{
	int n, i;
	
	scanf ("%d", &n);
	vec = vector <int> (n);
	for (int& a : vec)
		scanf ("%d", &a);

	int res = 0;
	for (i=0; i<28; i++)
		{
		out[i] = solve(i);
		if (out[i] == 1)
			res += (1<<i);
		//printf ("out[%d] = %d\n", i, out[i]);
		}
	
	printf ("%d\n", res);
	return 0;
	}