#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

#define sz(x) (int)((x).size())

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), s = nxt() - 1;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int ans = 0;
	if (a[s]) {
		a[s] = 0;
		++ans;
	}

	swap(a[s], a.back());
	a.pop_back();
	sort(all(a));
	int lst = 0;
	int i = 0;
	while (i < (int)a.size() && !a[i]) {
		++i;
	}
	int charge = i;
	for (; i < (int)a.size();) {
		if (a[i] > lst + 1) {
			++lst;
			if (charge) {
				--charge;
			} else {
				a.pop_back();
			}
			++ans;
		} else {
			lst = a[i];
			++i;
		}
	}
	ans += charge;

	printf("%d\n", ans);

	return 0;
}