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
const int size = 300;
const int bsize = 1000 * 1000 + 100;

int ans[bsize];
long long x[size], y[size];

int main() {
	int n, m;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		ans[i] = 1;
	for (int i = 0; i < m; i++)
		cin >> x[i] >> y[i];
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
		{
			int sum = 0;
			long long a = y[i] - y[j], b = x[j] - x[i];
			long long c = - a * x[i] - b * y[i];
			for (int k = 0; k < m; k++)
				if (a * x[k] + b * y[k] + c == 0)
					sum++;
			if (a == 0)
				continue;
			if (-c % a != 0)
				continue;
			if (-c / a >= 1 && -c / a <= n)
				ans[-c / a] = max(ans[-c / a], sum);
		}
	long long sans = 0;
	for (int i = 1; i <= n; i++)
		sans += ans[i];
	cout << sans;

	return 0;
}