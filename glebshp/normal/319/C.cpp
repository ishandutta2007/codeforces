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

long long a[size], b[size];

long long comp(pair <long long, long long> a, pair <long long, long long> b) {
	long long d = b.fs - a.fs;
	long long z = a.sc - b.sc;
	return (d + z - 1) / z;
}

long long ans[size];

int main() {
	int n;

	//freopen("problem_c.in", "r", stdin);
	//freopen("problem_c.out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &b[i]);
	ans[0] = b[0];
	vector <pair <long long, long long> > st;
	st.pb(mp(0, 0));
	for (int i = 1; i < n; i++) {
		int lb = 0;
		int rb = int(st.size()) - 1;
		int mid;
		while (lb < rb) {
			mid = (lb + rb + 1) / 2;
			if (st[mid].fs > a[i])
				rb = mid - 1;
			else
				lb = mid;
		}
		ans[i] = ans[st[lb].sc] + b[st[lb].sc] * (a[i] - 1) + b[i];
		while (!st.empty() && comp(mp(ans[st.back().sc], b[st.back().sc]), mp(ans[i], b[i])) <= st.back().fs)
			st.pop_back();
		if (st.empty())
			st.pb(mp(0, i));
		else
			st.pb(mp(comp(mp(ans[st.back().sc], b[st.back().sc]), mp(ans[i], b[i])), i));
	}

	cout << ans[n - 1] << endl;

	return 0;
}