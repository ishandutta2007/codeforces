#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;

int n, m;
int a[100105], b[100105];

bool check(ll x) {
    int ai = 0, bi = 0;
    while (ai < n) {
        while (bi < m && b[bi] + x < a[ai]) ++bi;
        if (bi == m || a[ai] + x < b[bi]) return false;
        ++ai;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];
    ll L = 0, R = 2e9;
    while (L < R) {
        ll mid = (L + R) / 2;
        if (check(mid)) R = mid;
        else L = mid + 1;
    }
    cout << L;

    return 0;
}