#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MX = 2.1e5;
int n;
ll r;
ll len[MX];
ll timeLimit[MX];

int main()
{
    cin >> n >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> len[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> timeLimit[i];
        if (timeLimit[i] < len[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    ll juiceTime = 0;
    vector<ll> drinkPosns;
    ll ctime = 0;
    ll ans = 0;
    const int LIM = 1e5;
    for (int i = 0; i < n; i++)
    {
        ll b = len[i];
        if (juiceTime >= b)
        {
            juiceTime -= b;
            ctime += b;
            continue;
        }
        ll margin = juiceTime + 2 * (b - juiceTime) - timeLimit[i];
        if (margin <= 0)
        {
            ctime += juiceTime + 2 * (b - juiceTime);
            juiceTime = 0;
            continue;
        }
        ll full = margin / r;
        ll partial = margin % r;
        ans += full;
        ans += !!partial;
        ctime += juiceTime;
        b -= juiceTime;
        juiceTime = 0;
        if (ans <= LIM)
        {
            while (full--)
            {
                drinkPosns.push_back(ctime);
                ctime += r;
                b -= r;
            }
            if (partial)
            {
                ll runLen = b - partial;
                ctime += 2 * runLen;
                drinkPosns.push_back(ctime);
                ctime += partial;
            }
            else
            {
                ctime += 2 * b;
            }
        }
        if (partial)
        {
            juiceTime = r - partial;
        }
    }
    cout << ans << endl;
    if (ans <= LIM)
    {
        for (int i = 0; i < drinkPosns.size(); i++)
        {
            if (i > 0)
            {
                cout << ' ';
            }
            cout << drinkPosns[i];
        }
        cout << endl;
    }
}