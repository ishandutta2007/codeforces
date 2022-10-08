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
#define taskname "problem_b"

const double pi = acos(-1.0);
const int size = 50 * 1000 + 100;
const int ssize = 102;

int ans[ssize][size];

vector <int> pos[26];
char buf[size];
int n;

int main() {
	/*
	freopen("input.txt", "w", stdout);
	for (int i = 0; i < 50 * 1000; i++)
		cout << 'z';
	cout << endl;
	return 0;
	*/
	//assert(freopen("input.txt", "r", stdin));
	///assert(freopen("output.txt", "w", stdout));
	
	scanf("%s", buf);
	n = strlen(buf);

	for (int i = 0; i < n; i++) {
		pos[buf[i] - 'a'].pb(i);
	}

	for (int i = 0; i < n; i++) {
		ans[0][i] = -1;
		ans[1][i] = i;
	}

	int mx = 1;
	for (int i = 2; i <= 100; i++) {
		n = n;
		for (int j = 0; j < 26; j++) {
			int mn = n;
			int ph = n - 1;
			int ps = pos[j].size();
			for (int k = (int) pos[j].size() - 1; k >= 0; k--) {
				while (ph > pos[j][k]) {
					mn = min(mn, ans[i - 2][ph]);
					ph--;
				}
				while (ps - 1 > k && pos[j][ps - 1] > mn)
					ps--;
				if (ps != (int) pos[j].size()) {
					mx = i;
					ans[i][pos[j][k]] = pos[j][ps];
				} else {
					ans[i][pos[j][k]] = n;
				}
			}
		}
	}

	int p = -1;
	for (int i = 0; i < n; i++)
		if (ans[mx][i] < n)
			p = i;
	string s;
	while (mx > 1) {
		s += buf[p];
		for (int i = p + 1; i <= ans[mx][p]; i++)
			if (ans[mx - 2][i] < ans[mx][p]) {
				p = i;
				mx -= 2;
				break;
			}
	}
	cout << s;
	if (mx > 0)
		cout << buf[p];
	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}