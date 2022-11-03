#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;
const int A = 1e6 + 13;
const int M = 1e9 + 7;

int sum(int a, int b) {
    int res = a + b;

    while(res >= M)
        res -= M;

    return res;
}

int mult(int a, int b) {
    return a * 1ll * b % M;
}

int diff(int a, int b) {
    return sum(a, M - b);
}

int t[A];

int get(int i) {
	int res = 0;
	for ( ; i >= 0; i = (i & (i + 1)) - 1)
		res = sum(res, t[i]);

	return res;
}

void upd(int i, int d) {
	for ( ; i < A; i = (i | (i + 1)))
		t[i] = sum(t[i], d);
}


int a[N];

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        int x = get(a[i]);
        int prev = diff(x, get(a[i] - 1));

        int res = diff(sum(mult(x, a[i]), a[i]), prev);

//        cout << i << ' ' << x << ' ' << res << endl;

        upd(a[i], res);

        ans = sum(ans, res);
    }

    cout << ans;
}