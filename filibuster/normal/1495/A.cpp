#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;
using vi = vector<int>;
using matr = vector<vi>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


/*
*/

void solve() {
    int n;
    cin >> n;

    vector<int> a, b;
    for(int i = 0; i < n * 2; i++) {
        int x, y;
        cin >> x >> y;

        x = abs(x);
        y = abs(y);

        if(x == 0)
            a.push_back(y);
        else
            b.push_back(x);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    ld ans = 0;
    for(int i = 0; i < n; i++) {
        ans += sqrt(a[i] * 1ll * a[i] + b[i] * 1ll * b[i]);
    }
    cout << setprecision(20) << fixed << ans << endl;
}

int main() {


    int t = 1;
    cin >> t;

    while(t--)
        solve();
}