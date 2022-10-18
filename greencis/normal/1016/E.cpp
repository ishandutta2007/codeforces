#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

ll sy, a, b;
ll n;
vector<int> v, sum;
int q;
ll x, y;

pair<ld, ld> query(ll x, ll y, ll b) {
    ld a = (b * y - x * sy) / ld(y - sy);
    int index = lower_bound(all(v), (int)ceil(a)) - v.begin();
    if (index % 2 != 0)
        return {sum[index - 1], a};
    return {sum[index - 1] + (a - v[index - 1]), a};
}

int main() {
    ios_base::sync_with_stdio(false);

    cin >> sy >> a >> b >> n;
    v.push_back(0);
    sum.push_back(0);
    for (int i = 0; i < n; ++i) {
        cin >> x >> y;
        v.push_back(x);
        v.push_back(y);
        sum.push_back(sum.back());
        sum.push_back(sum.back() + y - x);
    }
    v.push_back(1000000001);
    sum.push_back(sum.back());

    cin >> q;
    while (q--) {
        cin >> x >> y;
        auto p1 = query(x, y, b);
        auto p2 = query(x, y, a);
        cout << setprecision(17) << fixed << (b - a) * ((p2.first - p1.first) / (p2.second - p1.second)) << "\n";
    }
}