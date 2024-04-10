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

ll n, m, k, q, p, ans, l, r, i, j, x, y, a[500001], b[11][11][11];
vector <ll> c[300001];
vector <ll> v;
ll d[1000001];
bool t[1000001];
ll s;

void gg(ll n)
{
        ll l=n, k=2, p=n+2+1+s, e=sqrt(n)+1;
        for (int i = e; i > 0; i--)
            if (n%(i*(i+1)/2)==0)
            {
                //if (p<=1e5) break;
                ll x=n/(i*(i+1)/2);
                if (p>x+i+2+s) p=x+i+2+s, l=x, k=i+1;
                if (p<=1e5) break;
            }
        if (p>1e5 || l*k*(k-1)/2!=n) s++, gg(n-1); else
        {
            //cout << p << " " << l+k+s+1 << " " << s+l*k*(k-1)/2 << "\n";
            for (int i = 0; i < l; i++) cout << 1;
            for (int i = 0; i < k-2; i++) cout << 3;
            for (int i = 0; i < s; i++)cout <<1;
            cout << 337;
            return;
        }
}

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        ll n;
        cin >> n;
        gg(n);
        s=0;
        cout << "\n";
    }
    return 0;
}