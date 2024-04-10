#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> pz, ng;
        bool z = 0;
        ll sol = -(ll) 1e18;
        for (int i = 1; i <= n; i++)
        {
            ll x;
            cin >> x;
            if (x == 0)
            {
                z = 1;
            }
            if (x > 0)
            {
                pz.push_back(x);
            }
            if (x < 0)
            {
                ng.push_back(x);
            }
        }
        if (z)
        {
            sol = 0;
        }
        sort(pz.begin(), pz.end());
        sort(ng.begin(), ng.end());
        for (int cpz = 0; cpz <= 5; cpz++)
        {
            int cng = 5 - cpz;
            if (cpz > (int) pz.size() || cng > (int) ng.size())
            {
                continue;
            }
            if (cng % 2 == 0)
            {
                ll cur = 1;
                for (int i = 0; i < cng; i++)
                {
                    cur *= ng[i];
                }
                for (int i = (int) pz.size() - cpz; i < (int) pz.size(); i++)
                {
                    cur *= pz[i];
                }
                sol = max(sol, cur);
            }
            else
            {
                ll cur = 1;
                for (int i = (int) ng.size() - cng; i < (int) ng.size(); i++)
                {
                    cur *= ng[i];
                }
                for (int i = 0; i < cpz; i++)
                {
                    cur *= pz[i];
                }
                sol = max(sol, cur);
            }
        }
        cout << sol << "\n";
    }
}