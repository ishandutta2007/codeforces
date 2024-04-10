#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N = 1e5 + 7;

#define int long long

int pr[N];
ll sum[N];

int get(int a) {    
    return (a == pr[a] ? a : pr[a] = get(pr[a]));
}

ll ans = 0;

void merge(int a, int b) {
    a = get(a);
    b = get(b);
    if (a != b) {
        pr[a] = b;
        sum[b] += sum[a];
        ans = max(ans, sum[b]);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    vector <int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        --p[i];
    }
    vector <ll> res(n);
    vector <int> have(n);
    for (int i = n - 1; i >= 0; --i) {
        res[i] = ans;
        int x = p[i];
        have[x] = 1;
        pr[x] = x;
        sum[x] = a[x];
        ans = max(ans, sum[x]);
        if (x && have[x - 1]) merge(x, x - 1);
        if (x != n - 1 && have[x + 1]) merge(x, x + 1);
    } 
    for (int i = 0; i < n; ++i) {
        cout << res[i] << '\n';
    }
}