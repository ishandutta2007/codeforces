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
const long long inf = 1000ll * 1000 * 1000 * 1000;
const int size = 50;

int a[size], b[size], k[size], p[size], na[size], back[size];
int n, u, r;
long long ans;

long long calc_ans()
{
	long long sum = 0;
	for (int i = 0; i < n; i++)
		sum += a[i] * k[i];
	return sum;
}

void dofirst()
{
	for (int i = 0; i < n; i++)
		a[i] ^= b[i];
}

void dosecond()
{
	for (int i = 0; i < n; i++)
		na[i] = a[p[i]] + r;
	for (int i = 0; i < n; i++)
		a[i] = na[i];
}

void backsecond()
{
	for (int i = 0; i < n; i++)
		na[i] = a[back[i]] - r;
	for (int i = 0; i < n; i++)
		a[i] = na[i];
}

void rec(int sn, int lst)
{
	if (sn % 2 == 0)
	{
		ans = max(ans, calc_ans());
	}
	if (sn == 0)
		return;
	if (lst == 0)
	{
		dofirst();
		rec(sn - 1, 1);
		dofirst();
	}
	dosecond();
	rec(sn - 1, 0);
	backsecond();
}

int main() {
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> u >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> k[i];
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
		p[i]--;
	}
	for (int i = 0; i < n; i++)
		back[p[i]] = i;
	ans = -inf;
	rec(u, 0);

	cout << ans << endl;

	return 0;
}