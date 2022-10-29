#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
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

ll n, m, k, q, ans=0, l, r, i, j, x, y, kol=0, a[1000001];
vector <ll> v, z;
string s;
bool tt[1000001];
ll d[1000001];

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll a, b , n;
        cin >> a >> b >> n;
        ll p=a^b;
        if (n%3==0)
        {
            cout << a;
        } else
        if (n%3==1) cout << b; else cout << p;
        cout << "\n";
    }
    return 0;
}