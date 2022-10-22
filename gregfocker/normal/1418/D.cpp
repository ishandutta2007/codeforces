#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

typedef long long ll;

ll n;
set<ll> s;
multiset<ll> d;

void add(ll x)
{
    s.insert(x);
    auto it = s.find(x);
    ll a = -1, b = -1;
    if (it != s.begin())
    {
        it--;
        a = *it;
        it++;
    }
    it++;
    if (it != s.end())
    {
        b = *it;
    }
    if (a != -1 && b != -1)
    {
        d.erase(d.find(b - a));
    }
    if (a != -1)
    {
        d.insert(x - a);
    }
    if (b != -1)
    {
        d.insert(b - x);
    }
}

void del(ll x)
{
    auto it = s.find(x);
    ll a = -1, b = -1;
    if (it != s.begin())
    {
        it--;
        a = *it;
        it++;
    }
    it++;
    if (it != s.end())
    {
        b = *it;
    }
    s.erase(x);
    if (a != -1)
    {
        d.erase(d.find(x - a));
    }
    if (b != -1)
    {
        d.erase(d.find(b - x));
    }
    if (a != -1 && b != -1)
    {
        d.insert(b - a);
    }
}

void print()
{
    if ((ll) s.size() <= 2)
    {
        cout << "0\n";
    }
    else
    {
        int first = *s.begin();
        auto it = s.end();
        it--;
        int last = *it;
        auto kek = d.end();
        kek--;
        cout << -*kek - first + last << "\n";
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, q;
    cin >> n >> q;
    for (ll i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        add(x);
    }
    print();
    for (ll i = 1; i <= q; i++)
    {
        ll tp, x;
        cin >> tp >> x;
        if (tp == 0)
        {
            del(x);
        }
        else
        {
            add(x);
        }
        print();
    }
}