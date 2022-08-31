#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

int main() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<int> b(n - 1);
	for (int i = 0; i < n - 1; ++i) {
		b[i] = min(a[i], a[i + 1]);
	}

	if (n == 1) {
		cout << a[0] << "\n";
		return 0;
	}

	int amax = 0, bmax = 0;
	if (n % 2 == 0) {
		bmax = b[n / 2 - 1];
	} else {
		amax = a[n / 2];
	}
	for (int i = 0; i < n; ++i) {
		if ((n - i) % 2) {
			if (n == i + 1) {
				printf("%d ", *max_element(all(a)));
				continue;
			}
			bmax = max(bmax, b[(n - 1 + i) / 2]);
			bmax = max(bmax, b[(n - 3 - i) / 2]);
			printf("%d ", bmax);
		} else {
			amax = max(amax, a[(n + i) / 2]);
			amax = max(amax, a[(n - 2 - i) / 2]);
			printf("%d ", amax);
		}
	}
	printf("\n");

	return 0;
}