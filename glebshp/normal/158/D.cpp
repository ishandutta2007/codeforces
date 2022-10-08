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

const int size = 100 * 1000;

int b[size];

int main() {
	int n, ans = 0, la, p, step;
	
	//freopen("problem_d.in", "r", stdin);
	//freopen("problem_d.out", "w", stdout);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
		ans += b[i];
	}
	for (int i = 3; i < n; i++)
		if (n % i == 0)
		{
			step = n / i;
			for (int j = 0; j < step; j++)
			{
				la = 0;
				p = j;
				while (p < n)
				{
					la += b[p];
					p += step;
				}
				ans = max(ans, la);
			}
		}
	cout << ans << endl;

	return 0;
}