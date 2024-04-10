#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, x, k, ans, b[200005];
ll a[200005];
string s, d;
vector <pll> v;
//bool t[10000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    //ll x, y, z;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    ll j=n, mx=0;
    while (b[j]!=0 && b[j-1]+1==b[j]) j--;
    if (b[j+1]==1)
    {
        ll mx=0;
        for (int i = 1; i <= j; i++)
            if (b[i]!=0)mx=max(mx, max(0ll, i-b[i]+1+(n-j)));
        if (mx==0)
        {
            cout << j << "\n";
            exit(0);
        }
    }
    mx=0;
    for (int i = 1; i <= n; i++)
        if (b[i]!=0)mx=max(mx, max(0ll, i-b[i]+1));
    cout << mx+n;
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/