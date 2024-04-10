#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
	int x;
	scanf("%d", &x);
	return x;
}

int main(){

	int n = nxt(), m = nxt();
	vector<pair<int, int>> b(n);
	vector<int> p(n);
	for (int i = 0; i < n; i++)
		b[i] = {nxt(), i + 1};
	sort(all(b));
	vector<int> a(n);
	for (int i = 0; i < n; i++){
		p[b[i].second - 1] = i;
	}
	for (int i = 0; i < n; i++){
		a[i] = b[i].first;
	}
	if (n == 1){
		for (int i = 0; i < m; i++){
			printf("%d\n", 1);
		}
		return 0;
	}
	while (m--){
		int k = p[nxt() - 1], l = nxt();
		if (a[n - 1] - a[k] <= l){
			l -= a[n - 1] - a[k];
			k = n - 1;
			if (a[n - 1] - a[0] <= l){
				l -= a[n - 1] - a[0];
				k = 0;
				l %= (2 * (a[n - 1] - a[0]));
			} else {
				int i = lower_bound(all(a), a[n - 1] - l) - a.begin();
				k = i;
				l -= a[n - 1] - a[i];
			}
		}
		while (1){
			if (k == 0 && a[1] - a[0] > l)
				break;
			if (k == n - 1 && a[k] - a[k - 1] > l)
				break;
			if (k > 0 && k < n - 1 && a[k] - a[k - 1] > l && a[k + 1] - a[k] > l)
				break;
			int i = lower_bound(all(a), a[k] + l) - a.begin();
			if (i == n || a[i] != a[k] + l)
				i--;
			l -= a[i] - a[k];
			int j = lower_bound(all(a), a[i] - l) - a.begin();
			l -= a[i] - a[j];
			if (k == j){
				l %= (2 * (a[i] - a[j]));
			}
			k = j;
		}
		printf("%d\n", b[k].second);
	}

	return 0;
}