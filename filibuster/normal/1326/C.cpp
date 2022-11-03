#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < n; i++)

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 998244353;

void solve() {
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> a(n);

    forn(i, n) {
        cin >> a[i];
    }

    vector<int> b;

    li s = 0;
    for(int i = 0; i < n; i++)
        if(a[i] > n - k) {
            b.push_back(i);
            s += a[i];
        }

//    cout << s << endl;

    li ans = 1;
    for(int i = 0; i < b.size() - 1; i++) {
        int x = b[i + 1] - b[i];
        ans = ans * 1ll * x % M;
    }

    cout << s << ' ' << ans << endl;
}