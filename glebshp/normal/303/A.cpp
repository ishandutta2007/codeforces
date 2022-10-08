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
const int size = 200 * 1000;

bool used[size];

int main() {
	//freopen("problem_a.in", "r", stdin);
	//freopen("problem_a.out", "w", stdout);
	
	int n;
	cin >> n;

	if (n % 2 == 0)
		printf("-1\n");
	else {
		for (int i = 0; i < n; i++)
			printf("%d ", i);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d ", i);
		printf("\n");
		for (int i = 0; i < n; i++)
			printf("%d ", (i + i) % n);
		printf("\n");
	}

	/*
	vector <int> h;

	cin >> n;
	for (int i = 0; i < n; i++)
		h.pb(i);
	do {
		bool flag = true;
		for (int i = 0; i < n; i++)
			used[i] = false;
		for (int i = 0; i < n; i++)
			used[(i + h[i]) % n] = true;
		for (int i = 0; i < n; i++)
			flag = flag && used[i];
		if (flag) {
			for (int i = 0; i < n; i++)
				cout << h[i] << ' ';
			cout << endl;
		}
	} while (next_permutation(h.begin(), h.end()));
	*/

	return 0;
}