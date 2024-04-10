#include <vector>
#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>
#include <assert.h>
using namespace std;

const int NMAX = 50010;
vector <int> adia[NMAX];
int ord[NMAX], last[NMAX], adancime[NMAX];
int perioada[NMAX];
int perioada_init[NMAX];
int active[NMAX];

void dfs(int nod, int& last_val, int h = 0)
{
	ord[nod] = last_val++;
	adancime[ord[nod]] = h;
	for (auto i : adia[nod])
		dfs(i, last_val, h + 1);
	last[ord[nod]] = last_val;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> perioada_init[i];

	for (int i = 2; i <= n; i++) {
		int tata;
		cin >> tata;
		adia[tata].push_back(i);
	}

	int last_val = 0;
	dfs(1, last_val);

	for (int i = 1; i <= n; i++)
		perioada[ord[i]] = perioada_init[i];
	
 	for (int t = 0; t < q; t++) {
		int nod;
		cin >> nod;
		nod = ord[nod];
		int sum_h = 0, nr = 0;
		for (int i = nod; i < last[nod]; i++) {
			int take = (active[i] <= t);
			sum_h += take * adancime[i];
			nr += take;
			active[i] = active[i] * (1 - take) + (t + perioada[i]) * take;
		}
		sum_h -= nr * adancime[nod];
		cout << sum_h << ' ' << nr << '\n';
	}
	
	return 0;
}