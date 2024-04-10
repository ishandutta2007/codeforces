#include <bits/stdc++.h>
using namespace std;

void ioThings() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
}

using ll = long long;
#define debug(x) cerr << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define pb push_back
#define fi first
#define se second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

int main() {
    ioThings();

    int n, a, b, k; cin >> n >> a >> b >> k;
    map<int, int> pts;
    
    while (n--) {
        int h; cin >> h;
        int r = (h - 1) % (a + b);
        pts[r / a]++;
    }

    int count = 0;
    for (auto& i : pts) {
        if (!i.fi)
            count += i.se;
        else {
            if (k >= i.fi * i.se) {
                k -= i.fi * i.se;
                count += i.se;
            } else {
                count += k / i.fi;
                break;
            }
        }
    }
    cout << count;

    return 0;
}