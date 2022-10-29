    #include <bits/stdc++.h>
    #include <ext/pb_ds/assoc_container.hpp>
    #include <ext/pb_ds/tree_policy.hpp>

    #pragma GCC optimize("-O3")
    #pragma GCC optimize("Ofast")
    #pragma GCC optimize("unroll-loops")
    #define mp make_pair
    #define ll long long
    #define fi first
    #define se second
    #define fr front()
    #define pb push_back
    #define sqr(a) ((a)*(a))
    #define pll pair<ll,ll>
    #define y1 Enkognit

    using namespace std;

    const ll MOD=1e9+7;

    int n, m, it, i, p, k, T, j, A, B, C, y, kol, b[200001], f[1000001];

    bool tt[200001];

    struct coord
    {
        ll x, y, z, num;
    };

    coord a[100001];

    bool comp(coord x,coord y)
    {
        return (x.x<y.x || (x.x==y.x && x.y<y.y) || (x.x==y.x && x.y==y.y && x.z<y.z));
    }

    int main()
    {
        ios::sync_with_stdio(0);
        cin.tie(0);cout.tie(0);
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y >> a[i].z,a[i].num=i+1;
        sort(a,a+n,comp);
        vector <pll> v;
        vector <coord> z, e;
        for (int i = 0; i < n; i++)
        {
            if (i+1<n && a[i].x==a[i+1].x && a[i].y==a[i+1].y)
            {
                cout << a[i].num << " " << a[i+1].num << "\n";
                i++;
            }else z.pb(a[i]);
        }
        for (int i = 0; i < z.size(); i++)
        {
            if (i+1<z.size() && z[i].x==z[i+1].x)
            {
                cout << z[i].num << " " << z[i+1].num << "\n";
                i++;
            }else e.pb(z[i]);
        }
        for (int i = 0; i < e.size(); i+=2)
        {
            cout << e[i].num << " " << e[i+1].num << "\n";
        }
    }