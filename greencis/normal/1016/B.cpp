#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, q;
string s, t;
vector<int> ans;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> q >> s >> t;
    for (int i = 0; i + m <= n; ++i) {
        if (s.substr(i, m) == t)
            ans.push_back(i);
    }
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x;
        y -= m - 1;
        if (x < y)
            cout << lower_bound(all(ans), y) - lower_bound(all(ans), x) << "\n";
        else
            cout << "0\n";
    }
}