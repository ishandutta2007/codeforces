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

vector <pair <int, int> > peop, arm, ans;

int main() {
	int n, m, x, y, a, b;

	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	scanf("%d%d%d%d", &n, &m, &x, &y);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		peop.pb(mp(a, i));
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &b);
		arm.pb(mp(b, i));
	}
	sort(peop.begin(), peop.end());
	sort(arm.begin(), arm.end());
	int p = 0;
	for (int i = 0; i < n; i++)
	{
		while (p < m && peop[i].fs - x > arm[p].fs)
			p++;
		if (p < m && peop[i].fs + y >= arm[p].fs)
		{
			ans.pb(mp(peop[i].sc, arm[p].sc));
			p++;
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < int(ans.size()); i++)
		printf("%d %d\n", ans[i].fs + 1, ans[i].sc + 1);

	return 0;
}