#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
const double pi = acos(-1.0);

int d12, d13, d14, d23, d24, d34;
int e1, e2, e3;

bool checkthree(int r1, int r2, int r3)
{
	if (r3 > r1 + r2)
		return false;
	if (r3 < abs(r1 - r2))
		return false;
	if ((r1 + r2 - r3) % 2 == 1)
		return false;
	return true;
}

bool accept(int k, int &a, int &b, int &c)
{
	c = d14 + d24 - 2 * k - e1 - e2;
	b = d14 + d34 - 2 * k - e1 - e3;
	a = d24 + d34 - 2 * k - e2 - e3;
	if (a < 0 || b < 0 || c < 0)
		return false;
	if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
		return false;
	a /= 2;
	b /= 2;
	c /= 2;
	if (a > e1 || b > e2 || c > e3)
		return false;
	return true;
}

int main() {
	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	cin >> d12 >> d13 >> d14 >> d23 >> d24 >> d34;
	if (!checkthree(d12, d23, d13))
	{
		cout << -1 << endl;
		return 0;
	}
	e1 = d12 - (d12 + d23 - d13) / 2;
	e2 = (d12 + d23 - d13) / 2;
	e3 = d23 - (d12 + d23 - d13) / 2;
	if (e1 < 0 || e2 < 0 || e3 < 0)
	{
		cout << -1 << endl;
		return 0;
	}
	int mx = min(d14, min(d24, d34));
	int a, b, c;
	for (int k = 0; k <= mx; k++)
	{
		if (accept(k, a, b, c))
		{
			string s1, s2, s3, s4;
			for (int i = 0; i < e1; i++)
			{
				s1 += 'a';
				s2 += 'b';
				s3 += 'b';
			}
			for (int i = 0; i < e2; i++)
			{
				s1 += 'b';
				s2 += 'a';
				s3 += 'b';
			}
			for (int i = 0; i < e3; i++)
			{
				s1 += 'b';
				s2 += 'b';
				s3 += 'a';
			}
			for (int i = 0; i < a; i++)
				s4 += 'a';
			for (int i = 0; i < e1 - a; i++)
				s4 += 'b';
			for (int i = 0; i < b; i++)
				s4 += 'a';
			for (int i = 0; i < e2 - b; i++)
				s4 += 'b';
			for (int i = 0; i < c; i++)
				s4 += 'a';
			for (int i = 0; i < e3 - c; i++)
				s4 += 'b';
			for (int i = 0; i < k; i++)
			{
				s1 += 'b';
				s2 += 'b';
				s3 += 'b';
				s4 += 'a';
			}
			cout << s1.length() << endl;
			cout << s1 << endl << s2 << endl << s3 << endl << s4 << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}