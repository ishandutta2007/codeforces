#include <bits/stdc++.h>
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

const ll MOD = 998244353;

ll n, k, l, m, r, i, j, x, y, ans, a[1000001];
pll b[200001];
bool tt[1000001];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    for (int i = 0; i< n; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        //if (x>=y+z) {cout << z+1 << "\n";;}else
        ll l=0, r=z+1;
        while (l<r)
        {
            ll w=(l+r)/2;
            if (x+w>y+z-w) r=w; else l=w+1;
        }
        cout << z-l+1 << "\n";
    }
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/