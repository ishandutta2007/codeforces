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
const int size = 2 * 1000 * 1000;

long long n, m;
char buf1[size], buf2[size];

int nod(int a, int b) {
	if (b == 0)
		return a;
	else
		return nod(b, a % b);
}

int c1[26], c2[26];

int main() {
	//assert(freopen("input.txt", "r", stdin));
	//assert(freopen("output.txt", "w", stdout));
	
	scanf("%I64d%I64d", &n, &m);
	scanf("%s%s", buf1, buf2);

	string s1(buf1);
	string s2(buf2);
	if (s1.size() < s2.size()) {
		swap(s1, s2);
		swap(n, m);
	}

	int l1 = s1.size();
	int l2 = s2.size();
	int d = nod(l1, l2);
	int len = l1 / d;

	long long ans = 0;

	for (int i = 0; i < d; i++) {
		int p = i;
		for (int j = 0; j < 26; j++) {
			c1[j] = 0;
			c2[j] = 0;
		}

		c1[s1[p] - 'a']++;
		c2[s2[p] - 'a']++;
		p = (p + l2) % l1;
		while (p != i) {
			c1[s1[p] - 'a']++;
			if (p < l2)
				c2[s2[p] - 'a']++;
			p = (p + l2) % l1;
		}

		ans += (m / len) * 1ll * len * 1ll * (l2 / d);
		for (int j = 0; j < 26; j++) {
			ans -= (m / len) * 1ll * c1[j] * 1ll * c2[j];
		}
	}

	cout << ans << endl;

	return 0;
}