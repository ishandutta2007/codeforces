#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m;
vector<int> vert, hor;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        vert.push_back(x);
    }
    vert.push_back(1e9);
    sort(all(vert), greater<int>());

    for (int i = 0; i < m; ++i) {
        int xa, xb, y;
        cin >> xa >> xb >> y;
        if (xa > 1)
            continue;
        hor.push_back(xb);
    }
    sort(all(hor), greater<int>());
    int ans = 1e9;
    int cur = 0;
    while (vert.size()) {
        while (hor.size() && hor.back() < vert.back())
            hor.pop_back();
        ans = min(ans, cur + (int)hor.size());
        vert.pop_back();
        ++cur;
    }
    cout << ans << endl;
}