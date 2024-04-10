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

const int size = 2 * 1000;
const int inf = 1000 * 1000 * 1000;

int c[size], tp[size];
vector <pair <int, int> > tab, pen;
vector <int> ans[size];

void produce_answer(int n, int k)
{
	long long ans_val = 0;
	int mn;
	long long sum;
	for (int i = 0; i < k; i++)
	{
		bool flag = false;
		sum = 0;
		mn = inf;
		for (int j = 0; j < ans[i].size(); j++)
		{
			sum += 2ll * c[ans[i][j]];
			mn = min(c[ans[i][j]], mn);
			if (tp[ans[i][j]] == 1)
				flag = true;
		}
		if (flag)
			sum -= mn;
		ans_val += sum;
	}
	if (ans_val % 2 == 0)
		cout << ans_val / 2 << ".0" << endl;
	else
		cout << ans_val / 2 << ".5" << endl;
	for (int i = 0; i < k; i++)
	{
		cout << ans[i].size() << ' ';
		for (int j = 0; j < int(ans[i].size()); j++)
			cout << ans[i][j] + 1 << (j == int(ans[i].size()) - 1 ? '\n' : ' ');
	}
}

int main() {
	int n, k;
	
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> c[i] >> tp[i];
		if (tp[i] == 1)
			tab.pb(mp(c[i], i));
		else
			pen.pb(mp(c[i], i));
	}
	sort(tab.rbegin(), tab.rend());
	for (int i = 0; i < min(int(tab.size()), k - 1); i++)
		ans[i].pb(tab[i].sc);
	int lst = min(int(tab.size()), k - 1);
	for (int i = lst; i < int(tab.size()); i++)
	{
		bool flag = false;
		for (int j = lst; j < k; j++)
			if (ans[j].size() == 0)
			{
				ans[j].pb(tab[i].sc);
				flag = true;
				break;
			}
		if (!flag)
			ans[lst].pb(tab[i].sc);
	}
	for (int i = 0; i < int(pen.size()); i++)
	{
		bool flag = false;
		for (int j = lst; j < k; j++)
			if (ans[j].size() == 0)
			{
				ans[j].pb(pen[i].sc);
				flag = true;
				break;
			}
		if (!flag)
			ans[lst].pb(pen[i].sc);
	}
	produce_answer(n, k);

	return 0;
}