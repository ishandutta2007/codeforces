#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 2e5 + 100;

int t[maxn];
int n;
int a, b, c;
multiset<int> st;

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    scanf("%d%d%d", &a, &b, &c);
    if (a > b) {
        swap(a, b);
    }
    if (b > c) {
        swap(b, c);
    }
    if (a > b) {
        swap(a, b);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", t + i);
        st.insert(t[i]);
        if (t[i] > a + b + c) {
            cout << -1 << endl;
            return 0;
        }
    }
    int toadd = 0;
    while (sz(st) && *st.rbegin() > b + c) {
        toadd++;
        st.erase(st.lower_bound(*st.rbegin()));
    }
    while (sz(st) && *st.rbegin() > c) {
        int cur = *st.rbegin();
        st.erase(st.lower_bound(cur));
        if (cur <= a + b) {
            auto it = st.upper_bound(c);
            if (it != st.begin()) {
                it--;
                st.erase(it);
            }
        } else if (cur <= a + c) {
            auto it = st.upper_bound(b);
            if (it != st.begin()) {
                it--;
                st.erase(it);
            }
        } else {
            auto it = st.upper_bound(a);
            if (it != st.begin()) {
                it--;
                st.erase(it);
            }
        }
        toadd++;
    }
    int x = 0, y = 0, t1 = 0, t2 = 0;
    for (auto i : st) {
        if (i <= a) {
            x++;
        } else if (i <= b) {
            y++;
        } else if (i <= a + b) {
            t1++;
        } else {
            t2++;
        }
    }
    int ans = INF;
    for (int r = 0; r * 2 <= t1 + t2 && r <= t1; r++) {
        int L = -1, R = INF;
        while (R - L > 1) {
            int cur = (L + R) / 2;
            int nx[3] = {x, y, t1 + t2 - r * 2};
            for (int j = 2; j >= 0; j--) {
                int can = cur;
                for (int i = j; i >= 0; i--) {
                    int d = min(can, nx[i]);
                    nx[i] -= d;
                    can -= d;
                }
            }
            bool ok = true;
            for (int i = 0; i < 3; i++) {
                if (nx[i] > 0) {
                    ok = false;
                }
            }
            if (ok) {
                R = cur;
            } else {
                L = cur;
            }
        }
        ans = min(ans, toadd + L + 1 + r);
    }
    printf("%d\n", ans);
    return 0;
}