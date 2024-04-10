#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define ld long double
#define pll pair<ll,ll>
#define pld pair<ld,ld>

using namespace std;

ll n, m, k, l, r, ttt, x, y, i, T, t, j, kol, q;
pll a[10001], b[10001];
string s, d;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    while (n--)
    {
        ll a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a,a+3);
        if (a[0]+a[1]+1<a[2]) cout << "No\n"; else cout << "Yes\n";
    }
    return 0;
}
/*
4
2
3
8
5
10
1
11
15
*/