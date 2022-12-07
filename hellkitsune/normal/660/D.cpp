#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int x[2000], y[2000];
vector<PII> v;

int gcd(int a, int b) {
    while (b) a %= b, swap(a, b);
    return a;
}

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d%d", x + i, y + i);
    REP(i, n) REP(j, n) if (i != j) {
        v.pb(mp(x[i] - x[j], y[i] - y[j]));
    }
    int sz = (int)v.size();
    sort(v.begin(), v.end());
    LL ans = 0;
    for (int beg = 0; beg < sz; ) {
        int end = beg + 1;
        while (end < sz && v[beg] == v[end]) ++end;
        ans += (LL)(end - beg) * (end - beg - 1) / 2;
        beg = end;
    }
    assert(ans % 4 == 0);
    ans /= 4;
    cout << ans << endl;
    return 0;
}