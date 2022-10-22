#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct zl { ll a, b; };
bool cmp(const zl &a, const zl &b)
{
    return a.b < b.b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<zl> v(n);
    ll ans = 0;
    for (int i = 0; i < n; i++)
        cin >> v[i].a >> v[i].b, ans += v[i].a*2;
    sort(v.begin(), v.end(), cmp);
    int r = n-1; // odkial ideme kupovat
    ll cnt = 0;
    for (int i = 0; i < n; i++)
    {
        while (r >= 0 && cnt < v[i].b)
        {
            ll val = min(v[r].a, v[i].b - cnt);
            cnt += val;
            v[r].a -= val;
            if (!v[r].a) r--;
        }
        //cout << v[i].a << "\n";
        ans -= v[i].a;
        cnt += v[i].a;
        v[i].a = 0;
    }
    cout << ans << "\n";
    return 0;
}