#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k;
ll c[500010];
vector < int > a, b;
struct cmp {
    inline int operator () (int a, int b) {
        return c[a] != c[b] ? c[a] > c[b] : a < b;
    }
};
set < int, cmp > s;
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int x;
        scanf("%d", &x);
        if (x >= 0) a.push_back(x);
        else b.push_back(x);
    }
    sort(a.begin(), a.end(), greater < int > ());
    sort(b.begin(), b.end(), greater < int > ());
    ll ans = 0;
    for (auto i : a) ans += c[1], c[1] += i;
    for (int i = 1; i <= k + 1; i++) s.insert(i);
    for (auto i : b) {
        int cur = *s.begin();
        s.erase(s.begin());
        ans += c[cur];
        c[cur] += i;
        s.insert(cur);
    }
    cout << ans << endl;
}