#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 1e6;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef DEBUG
#define LLD "%lld"
#else
#define LLD "%I64d"
#endif

using namespace std;

const int N = 1e5 + 100;

int n, k;
int a[N];
bool b[N];
bool flag;

void solve(int l, int r, int mn, int mx) {
    if (mx - mn < (r - l) / k + 1) {
        flag = true;
        return;
    }
    int st = -(((r - l) / k - 1) / 2);
    if (st + (r - l) / k - 1 >= mx) {
        st = mx - (r - l) / k;
    }
    if (st <= mn) {
        st = mn + 1;
    }
    for (; l < r; l += k) {
        a[l] = st;
        st++;
    }
}

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "?") {
            b[i] = true;
        } else {
            a[i] = atoi(s.c_str());
        }
    }
    for (int i = 0; i < k; i++) {
        int prev = i - k;
        int prev_val = -INF;
        int j = i;
        for (; j < n; j += k) {
            if (b[j] == false) {
                solve(prev + k, j, prev_val, a[j]);
                prev = j;
                prev_val = a[j];
            }
        }
        solve(prev + k, j, prev_val, INF);
    }

    if (flag) {
        cout << "Incorrect sequence" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
    }
    return 0;
}