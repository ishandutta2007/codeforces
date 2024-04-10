#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 2000;
int f[N], m = 0;

void ins(int x) {
    f[x]++;
    while (f[m]) m++;
}

void rem(int x) {
    f[x]--;
    if (f[x] == 0) m = min(m, x);
    while (m > 0 && !f[m-1]) m--;
}

vector<int> a, r;

void op(int i) {
    int s = m;
    rem(a[i]);
    a[i] = s;
    ins(s);
    r.pb(i);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        fill(f, f+n+1, 0); m = 0;
        a.resize(n);
        for (auto& x : a) {
            cin >> x; ins(x);
        }
        r.clear();

        while (m != n) op(m);
        for (int i = 0; i < n; i++) {
            if (a[i] != i) {
                op(i);
                while (m != n)
                    op(m);
            }
        }

        debug(a);

        cout << r.size() << "\n";
        for (auto& x : r)
            cout << x+1 << " ";
        cout << '\n';
    }
}