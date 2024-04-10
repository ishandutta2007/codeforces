#include <iostream>
#include <ctime>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <map>

#define int long long
#define all(x) x.begin(), x.end()
#define pb emplace_back
#define mp make_pair

using namespace std;

void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    srand(time(NULL));
}

signed main() {
    setup();

    int t;
    cin >> t;
    for(int i = 0; i < t; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        int mx = max(a, b);
        mx = max(c, mx);
        int ost = a + b + c - mx;
        if (mx - 1 <= ost)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}