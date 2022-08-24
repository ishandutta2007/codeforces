#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

vector<int> zFunction(const vector<int>& s) {
    int n = s.size();

    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        z[i] = max(min(z[i - l], r - i), 0);

        while (i + z[i] < n && s[i + z[i]] == s[z[i]])
            ++z[i];

        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    
    if (n)
        z[0] = n;

    return z;
}

int main() {
	int n = nxt(), m = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	int x = a[0] + m;
	a.push_back(x);
	vector<int> d(n);
	for (int i = 0; i < n; ++i) {
		d[i] = a[i + 1] - a[i];
	}

	vector<int> z = d;
	reverse(all(d));
	z.insert(z.end(), all(d));
	z.insert(z.end(), all(d));

	// for (int x : z) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	z = zFunction(z);
	// for (int x : z) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		if (z[n + i] >= n) {
			ans.push_back((a[(n - i) % n] + a[0]) % m);
		}
	}
	sort(all(ans));
	printf("%d\n", (int)ans.size());
	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}