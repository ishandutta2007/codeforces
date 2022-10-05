#include <vector>
#include <algorithm>
#include <iostream>
#include <set>
#include <queue>
#include <iomanip>

using namespace std;

typedef long long ll;

vector <int> dx = {0, 0, -1, 1};
vector <int> dy = {-1, 1, 0, 0};

set <pair <int, int>> used;

ll n, m, r, k;

ll calc(int x, int y) {
    return (min(n + 1, x * 1LL + r) - max(x * 1LL, r)) * (min(m + 1, y * 1LL + r) - max(y * 1LL, r));
}

bool check(int x, int y) {
    return 1 <= x && x <= n && 1 <= y && y <= m;
}

struct cmp {
    bool operator()(const pair <int, int> &f, const pair <int, int> &s){
        ll fa = calc(f.first, f.second);
        ll fb = calc(s.first, s.second);
        return fa == fb ? f > s : fa > fb;
    }
};

int main() {
    cin >> n >> m >> r >> k;
    set<pair <int, int>, cmp> q;
    q.insert({(n + 1) / 2, (m + 1) / 2});
    set <pair <int, int>> used;
    used.insert({(n + 1) / 2, (m + 1) / 2});
    ll cnt = 0;
    while (k > 0) {
        auto p = *q.begin();
        q.erase(q.begin());
        cnt += calc(p.first, p.second);
        --k;
        for (int i = 0; i < 4; ++i) {
            int tx = p.first + dx[i];
            int ty = p.second + dy[i];
            if (check(tx, ty) && !used.count({tx, ty})) {
                q.insert({tx, ty});
                used.insert({tx, ty});
            }
        }
    }
    cout << fixed << setprecision(16) << (long double)cnt / (n - r + 1) / (m - r + 1) << endl;
    return 0;
}