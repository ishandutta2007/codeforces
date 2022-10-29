#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define pll pair<ll,ll>

using namespace std;

ll n, m, k, l, r, i, j, a[1000001];
vector <ll> v, z;
string s, d;

int main()
{
    cin >> n;
    for (int i = 0; i< n; i++)
    {
        ll a, b, c;
        cin >> a >> b >> c;
        ll p=min(b,c/2), ans=p*3;
        b-=p;
        c-=p*2;
        p=min(a,b/2);
        ans+=p*3;
        cout << ans << "\n";
    }
    return 0;
}