#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define taskname "problem_e"

const double pi = acos(-1.0);
const int size = 3000;
const int lsize = 200 * 1000;
const int inf = 1000 * 1000 * 1000;

vector <int> vec[lsize];
int p[size];
int n;
int w[size];
int bans[size][size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
		p[i] = abs(p[i]);
		vec[p[i]].pb(i);
	}

	int cur = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			cur += (p[i] > p[j]);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++)
			if (p[j] < p[i])
				w[i]++;
		for (int j = i + 1; j < n; j++)
			if (p[j] < p[i])
				w[i]--;
	}

	int ans = 0;
	for (int i = 1; i < lsize; i++) {
		int m = vec[i].size();
		for (int j = 0; j <= m; j++)
			for (int k = 0; k <= m; k++)
				bans[j][k] = 0;
 
		for (int j = 1; j <= m; j++) {
			bans[j][0] = bans[j - 1][0];
			for (int k = 1; k <= j; k++)
				bans[j][k] = min(bans[j - 1][k], bans[j - 1][k - 1] + w[vec[i][j - 1]] + j - k);
		}

		int mn = inf;
		for (int k = 0; k <= m; k++)
			mn = min(mn, bans[m][k]);
		ans += mn;
	}

	cout << cur + ans << endl;

	return 0;
}