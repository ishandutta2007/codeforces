#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, k, l, ans, r, a[500001], T, o, an=0, b[101];
vector <ll> v;

int main()
{
    ios_base::sync_with_stdio(0);
    ll t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        bool t=0;
        for (int i = 0; i < 13; i++) b[i]=0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ll z=a[i], p=0;
            while (z)
            {
                z/=2;
                p++;
            }
            if (p<13)
            b[p]++;
        }
        for (int i = 0; i < 12; i++)
        {
            b[i+1]+=b[i]/2;
        }
        if (b[12]) cout << "YES\n"; else cout << "NO\n";
    }
    return 0;
}
/*
8 7
1 1 30 5 5 1 1 1
1 2
2 3
2 4
4 5
2 6
6 7
6 8
2
*/