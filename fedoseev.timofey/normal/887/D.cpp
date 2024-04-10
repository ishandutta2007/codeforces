#include <vector>
#include <iostream>
#include <set>

using namespace std;

const int Maxn = 3e5 + 7;

struct event {
    int x, type;
};
event q[Maxn];
long long pref1[Maxn];
long long pref2[Maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, a, b, c, d, start, len;
    cin >> n >> a >> b >> c >> d >> start >> len;
    for (int i = 1; i <= n; ++i) cin >> q[i].x >> q[i].type;
    q[0] = {-1, -1};
    pref1[0] = start;
    pref2[0] = start;
    for (int i = 1; i <= n; ++i) {
        pref1[i] = pref1[i - 1];
        pref2[i] = pref2[i - 1];
        if (q[i].type == 0) {
            pref1[i] -= b;
            pref2[i] -= d;
        }
        else {
            pref1[i] += a;
            pref2[i] += c;
        }
    }
    multiset <long long> mi;
    int pt = 1;
    for (int i = 0; i <= n; ++i) {
        if (pref1[i] < 0) {
            cout << -1 << endl;
            return 0;
        }
        if (i) mi.erase(pref2[i]);
        while (pt <= n && q[pt].x - (q[i].x + 1) < len) mi.insert(pref2[pt++]);
        if (mi.size() == 0) cout << q[i].x + 1 << endl, exit(0);
        long long val = *mi.begin();
        val += pref1[i] - pref2[i];
        if (val >= 0) cout << q[i].x + 1 << endl, exit(0);
    }
}