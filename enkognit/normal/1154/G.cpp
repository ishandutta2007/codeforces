#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))
#define pu push
#define ld long double
#define pld pair<ld,ld>
#define y1 Enkognit
//#define {cout.flush()} {fflush(stdout)}

using namespace std;

const ll MOD=1e9;

ll n, m, sum, ans=1e18, k, l, ls, r, i, j, p1, p2;
vector <ll> v[10000005];
ll a[10000005];

void ask(ll h,ll l,ll r)
{
    //cout << h << " " << l << " " << r << "\n";
    if (h<ans) ans=h, p1=l, p2=r;
}

int main()
{
    //freopen("cipher.in","r",stdin);
    //freopen("cipher.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("lexicon.in","r",stdin);
    //freopen("lexicon.out","w",stdout);
    cin >> n;
    pll o=mp(1e9,1e9), g=mp(0,0);
    for (int j = 1; j <= n; j++)
    {
        ll x;
        cin >> x;
        if (x<o.fi) swap(o.fi,o.se), swap(g.fi,g.se), g.fi=j, o.fi=x; else
        if (x<o.se) o.se=x, g.se=j;
        a[x]++;
        v[x].pb(j);
    }
    ans=o.fi*o.se, p1=g.fi, p2=g.se;
    //cout << g.fi << " " << o.se << "\n";
    //cout << a[2] << "\n";
    for (int i = 2; i <= 1e7; i++)
    {
        ll l=0, r=0, j=i, u1=0, u2=0;
        while (j<=1e7)
        {
            ll u=a[j], p=0;
            if (u)
            {
                u--;
                if (l==0) {l=j;u1=v[j][p];p++;} else {r=j;u2=v[j][p];p++;break;}
            }
            if (u)
            {
                u--;
                if (l==0) {l=j;u1=v[j][p];p++;} else {r=j;u2=v[j][p];p++;break;}
                p++;
            }
            j+=i;
        }
        //if (i==2) cout << l << " " << r << "\n";
        if (l && r) ask(l*r/i,u1,u2);
    }
    if (p1>p2)swap(p1,p2);
    cout << p1 << " " << p2 << "\n";
    return 0;
}