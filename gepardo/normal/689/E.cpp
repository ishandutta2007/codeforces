#include <iostream>
#include <vector>
#include <map>
#define int long long

using namespace std;

const int mod = (int)1e9 + 7;

int binpow(int a, int p)
{
    int res = 1;
    while (p)
    {
        if (p & 1) res *= a, res %= mod;
        a *= a, a %= mod;
        p >>= 1;
    }
    return res;
}

int rev(int a)
{
    return binpow(a, mod-2);
}

main()
{
    int n, k; cin >> n >> k;
    map <int, pair <int, int> > event;
    vector <int> c(n+1, 0);
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        event[a].first++;
        event[b].second++;
    }
    c[k] = 1;
    for (int i = k+1; i <= n; i++)
        c[i] = ((c[i-1] * i) % mod * rev(i - k)) % mod;
    int coord = (int)-1.5e9, cnt = 0;
    int ans = 0;
    for (auto it: event)
    {
        ans += (it.first - coord) * c[cnt], ans %= mod;
        cnt += it.second.first;
        ans += c[cnt], ans %= mod;
        cnt -= it.second.second;
        coord = it.first + 1;
    }
    cout << ans << endl;
}