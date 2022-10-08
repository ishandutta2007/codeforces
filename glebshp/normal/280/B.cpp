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

int n;

int main() {
	//freopen("problem_b.in", "r", stdin);
	//freopen("problem_b.out", "w", stdout);
	
	scanf("%d", &n);

	int ans = 0;

	vector <int> st;
	int d;

	for (int i = 0; i < n; i++) {
		scanf("%d", &d);

		while (st.size() > 0 && st.back() < d) {
			ans = max(ans, d ^ st.back());
			st.pop_back();
		}

		if (st.size() > 0) {
			ans = max(ans, d ^ st.back());
		}

		st.pb(d);
	}

	cout << ans << endl;

	return 0;
}