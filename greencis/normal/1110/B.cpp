#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, m, k, x;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        v.push_back(x);
    }
    ll ans = n;
    priority_queue<int> q;
    for (int i = 0; i + 1 < n; ++i)
        q.push(v[i + 1] - v[i] - 1);
    int cur = 1;
    while (cur < k)
        ++cur, q.pop();
    while (q.size())
        ans += q.top(), q.pop();
    cout << ans << endl;
}