#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>


using namespace std;


const int MAXN = 100 * 1000 + 7;
const long long magic = (long long)1e12;
long long a[MAXN];
bool bad[MAXN];


long long sum(int n, long long x) {
	long long res = 0;
	for (int i = 1; i <= n; i++) {
		res = res * x + a[i];
		if (abs(res) > magic) {
			return magic;
		}
	}
	return res;
}


long long getll(string s) {
	int l = 0;
	int znak = 1;
	if (s[l] == '-') {
		znak = -1;
		l++;
	}
	long long res = 0;
	for (int i = l; i < (int)s.length(); i++) {
		res = 10 * res + s[i] - '0';
	}
	res *= znak;
	return res;
}


int main() {
	int n, k;
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n + 1; i++) {
		string s;
		cin >> s;
		if (s == "?") {
			bad[i] = true;
		} else {
			a[i] = getll(s);
		}
	}
	reverse(a + 1, a + 1 + n + 1);
	reverse(bad + 1, bad + 1 + n + 1);
	int cntsteps = 0;
	for (int i = 1; i <= n + 1; i++) {
		if (!bad[i]) {
			cntsteps++;
		}
	}
	cntsteps %= 2;
	if (k == 0) {
		if (bad[n + 1]) {
			if (cntsteps == 0) {
				printf("No\n");
			} else {
				printf("Yes\n");
			}
		} else if (a[n + 1] == 0){
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	} else {
		int estbad = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (bad[i]) {
				estbad++;
			}
		}
		if (estbad == 0) {
			bool win = true;			
			if (sum(n + 1, k) != 0) {
				win = false;
			}			
			if (win && abs(a[n + 1]) % abs(k) == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		} else if (estbad % 2 == 1) {
			if (cntsteps == 0) {
				printf("No\n");
			} else {
				printf("Yes\n");
			}
		} else {
			if (cntsteps == 0) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		}
	}
	return 0;
}