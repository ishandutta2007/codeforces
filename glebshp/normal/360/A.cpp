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
#define taskname "problem_a"

const double pi = acos(-1.0);
const int inf = 1000 * 1000 * 100;
const int size = 10 * 1000;

int mas[size];
int bon[size];
int tp[size], lb[size], rb[size], val[size];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		mas[i] = inf;
	for (int i = 0; i < m; i++) {
		cin >> tp[i] >> lb[i] >> rb[i] >> val[i];
		lb[i]--;
		rb[i]--;
	}
	for (int i = 0; i < m; i++) {
		if (tp[i] == 1) {
			for (int j = lb[i]; j <= rb[i]; j++)
				bon[j] += val[i];
		} else {
			for (int j = lb[i]; j <= rb[i]; j++)
				mas[j] = min(mas[j], val[i] - bon[j]);
		}
	}

	for (int i = 0; i < n; i++)
		bon[i] = 0;

	bool flag = true;
	for (int i = 0; i < m; i++) {
		if (tp[i] == 1) {
			for (int j = lb[i]; j <= rb[i]; j++)
				bon[j] += val[i];
		} else {
			int mx = -inf;
			for (int j = lb[i]; j <= rb[i]; j++)
				mx = max(mx, mas[j] + bon[j]);
			if (mx != val[i])
				flag = false;
		}
	}

	if (flag) {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++)
			cout << mas[i] << " \n"[i == n - 1];
	} else {
		cout << "NO" << endl;
	}

	return 0;
}