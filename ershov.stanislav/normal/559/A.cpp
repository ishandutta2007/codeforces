#include <bits/stdc++.h>

#define pb push_back
#define eb emplace_back
#define fs first
#define sc second
#define all(x) x.begin(), x.end()

#define y1 hrhrthrtethet

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;
typedef long long ll;

ll sqr(ll a) {
    return a * a;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    ll a1, a2, a3, a4, a5, a6;
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    ll ans = 0;
    ans += sqr(a1 + a2 + a3);
    ans -= sqr(a1) + sqr(a3) + sqr(a5);
    cout << ans << endl;
    return 0;
}