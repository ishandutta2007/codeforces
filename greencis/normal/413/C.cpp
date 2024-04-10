#include <iostream>
#include <algorithm>
using namespace std;

int n,m,t;
long long res,ans;

struct entry {
    int a;
    bool auction;
} e[999];

int comp(entry a, entry b) {
    return a.auction == b.auction ? a.a > b.a : a.auction < b.auction;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> e[i].a;
    }
    for (int i = 0; i < m; ++i) {
        cin >> t;
        --t;
        e[t].auction = 1;
    }
    int mask = (1ll << m);
    sort(e,e+n,comp);
    for (int i = 0; i < n-m; ++i)
        res += e[i].a;
    for (int i = 0; i <= m; ++i) {
        ans = max(ans,res*mask);
        mask >>= 1ll;
        res += e[i+n-m].a;
    }
    cout << ans;

    return 0;
}