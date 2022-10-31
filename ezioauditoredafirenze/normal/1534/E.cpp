#include <bits/stdc++.h>

using namespace std;

#define debug(...) fprintf(stderr, __VA_ARGS__)
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define SZ(x)(int((x).size()))
#define ALL(x)(x).begin(), (x).end()

template <typename T> inline bool chkmin(T & a,
    const T & b) {
    return b < a ? a = b, 1 : 0;
}
template <typename T> inline bool chkmax(T & a,
    const T & b) {
    return a < b ? a = b, 1 : 0;
}

typedef long long LL;

const LL infinity = 0x3f3f3f3f3f3f3f3f;
const LL mod = 1e9 + 7;

int ask(vector <int>& q) {
    cout << "? ";
    for (int i = 0; i < SZ(q); i++) {
        cout << q[i] << " ";
    }
    cout << endl;
    int answer;
    cin >> answer;
    return answer;
}

void one(int k, int n) {
    int answer = 0;
    for (int i = 1; i <= n; i += k) {
        vector <int> q(k);
        for (int j = 0; j < k; j++) {
            q[j] = i + j;
        }
        answer = answer ^ ask(q);
    }
    cout << "! " << answer << endl;
    return;
}

void two(int k, int n, int delta) {
    int g = (n / k) - delta;
    int answer = 0;
    int i = 1, c;
    vector <int> a;
    vector <int> b;
    for (c = 0; c < g; i = i + k) {
        vector <int> q(k);
        for (int j = 0; j < k; j++) {
            q[j] = i + j;
        }
        answer = answer ^ ask(q);
        ++c;
    }
    c = 0;
    for (; i <= n; i += 2) {
        a.pb(i);
        b.pb(i + 1);
        ++c;
    }
    for (i = 1; i + c <= k; i++) {
        a.pb(i);
        b.pb(i);
    }
    answer = answer ^ ask(a) ^ ask(b);
    cout << "! " << answer << endl;
    return;
}

void three(int k, int n) {
    int answer = 0;
    int i = 1, rem = n;
    vector <int> free;
    for (; i < n;) {
        vector <int> a, b, c;
        a.pb(i);
        b.pb(i + 1);
        c.pb(i);
        c.pb(i + 1);
        i += 2;
        for (; i <= n && n >= i - SZ(free) + k - SZ(a);) {
            a.pb(i);
            b.pb(i + 1);
            c.pb(i);
            c.pb(i + 1);
            i += 2;
        }
        int j = i, p = 0, cn = k - SZ(a);
        for (; j <= n && cn > 0;) {
            a.pb(j);
            b.pb(j);
            --cn, ++j;
        }
        for (; cn > 0;) {
            a.pb(free[p]);
            b.pb(free[p]);
            --cn, ++p;
        }
        answer = answer ^ ask(a) ^ ask(b);
        for (int h = 0; h < SZ(c); ++h) {
            free.pb(c[h]);
        }
    }
    cout << "! " << answer << endl;
    return;
}

void solve() {
    int n, k;
    cin >> n >> k;
    if (n % k == 0) {
        one(k, n);
    } else if (n % 2 == 1 && k % 2 == 0) {
        cout << "-1" << endl;
    } else if (k % 2 == 0) {
        if (2 * k > n) {
            two(k, n, 0);
        } else {
            two(k, n, 1);
        }
    } else {
        int rem = (n % k) % 2;
        if (2 * k < n) {
            if (rem == 1) {
                two(k, n, 1);
            } else {
                two(k, n, 0);
            }
        } else {
            if (rem == 0) {
                two(k, n, 0);
            } else {
                three(k, n);
            }
        }
    }
    return;
}

int main() {
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}