#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
typedef long long LL;
typedef pair<int, int> PII;

LL n, k;

mt19937_64 mt(time(0));

bool query(LL from, LL to) {
    from = max(from, 1ll);
    to = min(to, n);
    cout << from << ' ' << to << endl;
    string ans;
    cin >> ans;
    assert(ans == "Yes" || ans == "No");
    if (ans == "Yes" && from == to) {
        exit(0);
    }
    return ans == "Yes";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    LL from = 1, to = n;
    while (true) {
        if (to < from + 50) {
            LL pos = mt() % (to - from + 1) + from;
            query(pos, pos);
            from = max(from - k, 1ll);
            to = min(to + k, n);
            continue;
        }
        LL mid = (from + to) / 2;
        if (query(from, mid)) {
            to = mid;
        } else {
            from = mid + 1;
        }
        from = max(from - k, 1ll);
        to = min(to + k, n);
    }
    return 0;
}