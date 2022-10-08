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
#define taskname "problem_d"

const double pi = acos(-1.0);
const int size = 200;

int n, m;
int k;
long long x;

long long tots1[size];
long long tots2[size];
long long tot[2][2][size];
int sts[size];
int fns[size];
char s1[size];
char s2[size];
char psb[size];

bool could(char* dst, int st, int fn, int need, int len) {
	dst[0] = psb[st];
	dst[len - 1] = psb[fn];
	for (int i = 1; i < len - 1; i++) {
		if (dst[i - 1] == 'A')
			dst[i] = 'C';
		else
			dst[i] = 'A';
	}

	int cnt = 0;
	for (int i = 0; i < len - 1; i++)
		cnt += (dst[i] == 'A' && dst[i + 1] == 'C');
	for (int i = 0; i < len - 1; i++) {
		if (cnt > need && dst[i] == 'A' && dst[i + 1] == 'C') {
			if (i > 0) {
				dst[i] = 'B';
				cnt--;
				continue;
			}
			if (i + 1 < len - 1) {
				dst[i + 1] = 'B';
				cnt--;
			}
		}
	}

	if (cnt == need && dst[0] == psb[st] && dst[len - 1] == psb[fn])
		return true;
	else
		return false;
}

inline bool goodpair(int smb1, int smb2) {
	return psb[smb1] == 'A' && psb[smb2] == 'C';
}

long long getresult(int st1, int fn1, int st2, int fn2, int n1, int n2, int k) {
	long long res = tots1[k] * n1 + tots2[k] * n2;
	if (goodpair(fn1, st1))
		res += tot[0][0][k];
	if (goodpair(fn1, st2))
		res += tot[0][1][k];
	if (goodpair(fn2, st1))
		res += tot[1][0][k];
	if (goodpair(fn2, st2))
		res += tot[1][1][k];

	return res;
}

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	cin >> k >> x >> n >> m;

	tots1[0] = 1;
	tots2[1] = 1;
	sts[0] = 1;
	fns[0] = 1;
	sts[1] = 2;
	fns[1] = 2;

	for (int i = 2; i < k; i++) {
		tots1[i] = tots1[i - 1] + tots1[i - 2];
		tots2[i] = tots2[i - 1] + tots2[i - 2];
		sts[i] = sts[i - 2];
		fns[i] = fns[i - 1];
		for (int p = 0; p < 2; p++)
			for (int q = 0; q < 2; q++)
				tot[p][q][i] = tot[p][q][i - 1] + tot[p][q][i - 2];
		tot[fns[i - 2] - 1][sts[i - 1] - 1][i]++;
	}

	psb[0] = 'A';
	psb[1] = 'C';
	psb[2] = 'B';

	for (int st1 = 0; st1 < 3; st1++)
		for (int fn1 = 0; fn1 < 3; fn1++)
			for (int st2 = 0; st2 < 3; st2++)
				for (int fn2 = 0; fn2 < 3; fn2++)
					for (int i = 0; i <= n / 2; i++)
						for (int j = 0; j <= m / 2; j++)
							if (could(s1, st1, fn1, i, n) && could(s2, st2, fn2, j, m) && getresult(st1, fn1, st2, fn2, i, j, k - 1) == x) {
								cout << s1 << endl;
								cout << s2 << endl;

								return 0;
							}
	cout << "Happy new year!" << endl;

	//for (int i = 1; i <= k; i++)
	//	cout << tots1[i - 1] << ' ' << tots2[i - 1] << ' ' << tot[0][0][i - 1] << ' ' << tot[0][1][i - 1] << ' ' << tot[1][0][i - 1] << ' ' << tot[1][1][i - 1] << endl;

	return 0;
}