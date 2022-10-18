#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,m,w,x;
vector<int> a;
queue< pii > q;

bool check(int num) {
    int curm = m;
    while (q.size()) q.pop();
    int curadd = 0;
    for (int i = 0; i < n; ++i) {
        while (q.size() && q.front().second == i) curadd -= q.front().first, q.pop();
        if (a[i] + curadd >= num) continue;
        int delta = num - a[i] - curadd;
        if (delta > curm) return false;
        curm -= delta;
        curadd += delta;
        q.push(make_pair(delta, i + w));
    }
    return true;
}

int main()
{
    cin >> n >> m >> w;
    int l=2e9, r = 2e9;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        a.push_back(x);
        l = min(l, x);
    }
    while (l < r) {
        int mid = int(((ll)l + (ll)r + 1ll) / 2ll);
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l;

    return 0;
}