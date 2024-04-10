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
#define taskname "problem_c"

const double pi = acos(-1.0);
const int mdl = 1000 * 1000 * 1000 + 7;
const int size = 2500;

int n, k;
string str;
int ans[size][size];
int psum[size][size];
long long pw[size];

int main() {
	/*
	freopen("input.txt", "w", stdout);
	cout << 2000 << ' ' << 2000 << endl;
	for (int i = 0; i < 2000; i++)
		cout << char('a' + rand() % 26);
	cout << endl;
	return 0;
	*/
	pw[0] = 1;
	for (int i = 1; i < size; i++) {
		pw[i] = (pw[i - 1] * 26) % mdl;
	}

	double sttm = clock();

	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> n >> k >> str;
	ans[0][0] = 1;
	psum[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			long long cura = psum[i - 1][j] * 1ll * (str[i - 1] - 'a');
			long long curb = 0;
			if (str[i - 1] < 'z')
				for (int p = i - 1; p >= 0; p--) {
					if ((i - p) * (n - i + 1) <= j) {
						cura += ans[p][j - (i - p) * (n - i + 1)] * 1ll * ('z' - str[i - 1]);
					} else {
						break;
					}
				}
			cura %= mdl;
			//curb %= mdl;
			//curb = (curb * pw[n - i]) % mdl;
			ans[i][j] = cura;
			//if (ans[i][j] >= mdl)
			//	ans[i][j] -= mdl;
			psum[i][j] = psum[i - 1][j] + ans[i][j];
			if (psum[i][j] >= mdl)
				psum[i][j] -= mdl;
		}
	}

	cout << psum[n][k] << endl;
	//cout << (clock() - sttm) / CLOCKS_PER_SEC << endl;

	return 0;
}