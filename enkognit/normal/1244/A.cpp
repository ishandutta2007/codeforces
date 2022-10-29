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
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

bool t[8000001];
ll n, m, k, l, r, a[1000001];

int main()
{

    //ios_base::sync_with_stdio(0);
    //for (int i = 0; i < n; i++) cin >> p[i];
    //for (int i = 0; i < n; i++) cout << p[i] << " ";
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        ll p=a/c+((a%c)>0);
        ll o=b/d+((b%d)>0);
        if (k<p+o) cout << -1; else cout << p << " " << o;;
        cout << "\n";
    }
    return 0;
}
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/