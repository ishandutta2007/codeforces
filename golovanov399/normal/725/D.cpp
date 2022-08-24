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

inline long long nxtll(){
	long long x;
	scanf("%I64d", &x);
	return x;
}

int main(){

	int n = nxt();
	vector<pair<long long, long long>> a(n - 1);
	long long t = nxtll(), w = nxtll();
	for (int i = 0; i < n - 1; i++) {
		a[i].first = nxtll();
		a[i].second = nxtll();
		a[i].second = a[i].second - a[i].first + 1;
		a[i].first = max(0ll, t - a[i].first + 1);
	}

	int ans = 1;
	sort(all(a));
	n--;
	for (int i = 0; i < n; i++) {
		if (a[i].first <= 0) {
			ans += 1;
		}
	}
	priority_queue<long long> used;
	priority_queue<long long, vector<long long>, greater<long long>> available;
	// for (int i = 0; i < n; i++) {
	// 	cerr << a[i].first << " " << a[i].second << "\n";
	// }
	long long wasted = 0;
	for (int i = 0; i < n; i++) {
		i--;
		do {
			i++;
			if (!used.empty() && used.top() > a[i].second) {
				// cerr << used.top() << " from used to available\n";
				available.push(used.top());
				wasted -= used.top();
				used.pop();
				// cerr << a[i].second << " to used\n";
				used.push(a[i].second);
				wasted += a[i].second;
			} else {
				// cerr << a[i].second << " to available\n";
				available.push(a[i].second);
			}
		} while (i < n - 1 && a[i + 1].first == a[i].first);
		if (t < a[i].first) {
			break;
		}
		long long limit = (i == n - 1) ? t : a[i + 1].first - 1;
		while (!available.empty() && available.top() <= limit - wasted) {
			// cerr << available.top() << " from abailable to used\n";
			wasted += available.top();
			used.push(available.top());
			available.pop();
		}
		// cerr << "tada " << 1 + i + 1 - (int)used.size() << "\n";
		ans = min(ans, 1 + i + 1 - (int)used.size());
	}

	printf("%d\n", ans);

	return 0;
}