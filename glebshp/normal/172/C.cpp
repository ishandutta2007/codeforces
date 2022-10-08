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

int n, m;
int t[size], x[size];
long long res[size];

int main() {
	map <int, vector <int> > incar;
	map <int, vector <int> > :: iterator it;

	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> t[i] >> x[i];
	}
	long long ans = 0;
	int ptr = 0;
	while (ptr < n)
	{
		if (int(incar.size()) > 0)
			ans += incar.rbegin() -> fs;
		incar.clear();
		ans = max(1ll * t[min(n - 1, ptr + m - 1)], ans);
		for (int i = ptr; i < min(ptr + m, n); i++)
			incar[x[i]].pb(i);
		int lstx = 0;
		for (it = incar.begin(); it != incar.end(); it++)
		{
			ans += it->fs - lstx;
			lstx = it->fs;
			for (int j = 0; j < int(it->sc.size()); j++)
				res[it->sc[j]] = ans;
			ans += (1 + int(it->sc.size()) / 2);
		}
		//ans += incar.rbegin() -> fs;
		ptr += m;
	}
	for (int i = 0; i < n; i++)
		cout << res[i] << (i + 1 == n ? '\n' : ' ');

	return 0;
}