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
const int size = 1000 + 10;

bool used[size];
int nx[size];
int pv[size];
bool could[size];
int cnt[size];

vector <int> h;

void dfs(int v) {
	if (used[v])
		return;
	used[v] = true;
	if (nx[v] == -1)
		cnt[v] = 1;
	else {
		dfs(nx[v]);
		cnt[v] = cnt[nx[v]] + 1;
	}
}

int main() {
	int n, x;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	scanf("%d%d", &n, &x);
	x--;
	for (int i = 0; i < n; i++) {
		nx[i] = -1;
		pv[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &nx[i]);
		nx[i]--;
		if (nx[i] != -1)
			pv[nx[i]] = i;
	}

	for (int i = 0; i < n; i++)
		dfs(i);
	could[0] = true;
	for (int i = 0; i < n; i++)
		if (pv[i] == -1) {
			int p = i;
			bool flag = true;
			while (p != -1) {
				flag = flag && (p != x);
				p = nx[p];
			}
			if (flag)
				for (int j = n - cnt[i]; j >= 0; j--)
					could[j + cnt[i]] = could[j + cnt[i]] || could[j];
		}
	for (int i = 0; i < n; i++)
		if (could[i])
			printf("%d\n", i + cnt[x]);

	return 0;
}