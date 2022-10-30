
#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
using namespace std;
long long m, n, v[200005], i, k, del, n1, pred[200005], j, s2, ans[200005], s1, fi, last;
vector<long long> vt[200005], pt, qt;
long long gcd(long long a, long long b)
{
	long long c;
	if (a < b)
	{
		c = a;
		a = b;
		b = c;

	}
	if (b == 0)
	{
		return a;
	}
	if (b > 0)
	{
		return gcd(b, a%b);
	}
}
long long b_p(long long a, long long b, long long c)
{
	if (b == 0)
	{
		return 1;
	}
	if (b % 2 == 1)
	{
		return(a*b_p(a, b - 1, c)) % c;
	}
	if (b % 2 == 0)
	{
		if (b > 0)
		{
			long long d = b_p(a, b / 2, c);
			return(d*d) % c;
		}
	}
}
long long del1(long long a, long long b, long long c, long long ty)
{
	long long d1, d2, d3, b1, a1, at;
	d1 = gcd(a, c);
	d2 = gcd(b, c);
	d3 = d2 / d1;
	a1 = a / d1;
	b1 = b / d2;
	at = (b1*d3*b_p(a1, ty - 1, c)) % c;
	return at;
}
int main()
{
	cin >> n >> m;
	for (i = 0; i < n; i++)
	{
		cin >> k;
		v[k] = 1;
	}
	fi = 0;
	for (i = 0; i < m; i++)
	{
		if (v[i] == 0)
		{
			k = gcd(i, m);
			vt[k].push_back(i);
		}
		if (gcd(i, m) == 1)
		{
			fi++;
		}
	}
	n1 = m;
	for (i = 2; i*i <= m; i++)
	{
		if (n1%i == 0)
		{
			k = 0;
			while (n1%i == 0)
			{
				k++;
				n1 = n1 / i;
			}
			pt.push_back(i);
			qt.push_back(k);
		}
	}
	if (n1 != 1)
	{
		pt.push_back(n1);
		qt.push_back(1);
	}
	del = pt.size();
	for (i = 1; i <= m; i++)
	{
		if (m%i == 0)
		{
			s2 = 0;
			s1 = -1;
			for (j = 0; j < del; j++)
			{
				if (i%pt[j] == 0)
				{
					s2 = max(s2, ans[i / pt[j]]);
					if (s2 == ans[i / pt[j]])
					{
						s1 = i / pt[j];
					}
				}
			}
			ans[i] = s2 + vt[m / i].size();
			//cout << ans[i] << endl;
			pred[i] = s1;
		}
	}
	n1 = m;
	cout << ans[m] << endl;
	last = 1;
	while (n1 != -1)
	{
		for (i = 0; i < vt[m / n1].size(); i++)
		{
			cout << del1(last, vt[m / n1][i], m, fi) << ' ';
			last = vt[m / n1][i];
		}
		n1 = pred[n1];
	}
}