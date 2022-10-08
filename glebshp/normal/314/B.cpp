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
const int mlog = 40;
const int size = 101;

long long jump[mlog][size][size];
int n, m;

long long needto(long long val) {
	long long p1 = 0;
	long long p2 = 0;
	long long np1, np2;
	long long sum = 0;
	for (int i = mlog - 1; i >= 0; i--) {
		if ((1ll << i) <= val) {
			sum += jump[i][p1][p2];
			p1 = (p1 + jump[i][p1][p2]) % n;
			p2 = (p2 + (1ll << i)) % m;
			val -= (1ll << i);
		}
	}

	return sum;
}

int main() {
	long long b, d;
	string s1, s2;

	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	cin >> b >> d;
	cin >> s1 >> s2;
	n = s1.size();
	m = s2.size();
	for (int i = 0; i < m; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++)
			flag = flag || s1[j] == s2[i];
		if (!flag) {
			cout << 0 << endl;
			return 0;
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			jump[0][i][j] = 0;
			while (s1[(i + jump[0][i][j]) % n] != s2[j])
				jump[0][i][j]++;
			jump[0][i][j]++;
		}

	for (int k = 1; k < mlog; k++) {
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				jump[k][i][j] = jump[k - 1][(i + jump[k - 1][i][j]) % n][(j + (1ll << (k - 1))) % m] + jump[k - 1][i][j];
	}

	long long lb = 0;
	long long rb = n * b / (m * d);
	while (lb < rb) {
		long long mid = (lb + rb + 1) / 2;
		if (needto(m * d * mid) > n * b)
			rb = mid - 1;
		else
			lb = mid;
	}

	cout << lb << endl;

	return 0;
}