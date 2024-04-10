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
const int size = 200;

int a[size][size], b[size][size], c[size][size];
vector <pair <int, int> > h;

int main() {
	string name;
	int n, m, k;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> name;
		for (int j = 0; j < m; j++)
			cin >> a[i][j] >> b[i][j] >> c[i][j];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i != j)
			{
				h.clear();
				for (int p = 0; p < m; p++)
					h.pb(mp(b[j][p] - a[i][p], c[i][p]));
				sort(h.rbegin(), h.rend());
				int hk = k;
				int sum = 0;
				for (int p = 0; p < m; p++)
					if (h[p].fs > 0)
					{
						sum += min(hk, h[p].sc) * h[p].fs;
						hk -= min(hk, h[p].sc);
					}
				ans = max(ans, sum);
			}

	cout << ans << endl;

	return 0;
}