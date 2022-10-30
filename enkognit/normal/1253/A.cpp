#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define tm stanislavpolyn

using namespace std;

ll MOD=1e9+7;

ll n, m, k, l, r, i, j, kl, x, y, b[1000001], a[2000001], c[1000001];
ld ans;
pll bn[200001][21];
map<ll,bool> tt;
string s;
vector <pll> v;

void solve()
{
    cin >> n;
    map<ll,bool> tt;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    for (int i = 1; i <= n; i++)
    {
        c[i]=a[i]-b[i];
    }
    ll ans=0, o=0, l=1e18, r=0;
    for (ll i = 1; i <= n;i++)
    {
        if (c[i]>0) {cout << "NO\n";return;}
        if (tt[c[i]]==0 && c[i]!=0) o++, tt[c[i]]=1;
        if (o>1) {cout << "NO\n";return;}
        if (c[i]!=0) l=min(l,i);
        if (c[i]!=0) r=i;
        ans+=c[i];
    }
    //cout << l << "  " << r << " " << o << " " << ans << "\n";
    if (o==0 && ans==0 || ans==c[l]*(r-l+1) && o==1) cout << "YES\n"; else cout << "NO\n";
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll q;
    cin >> q;
    while (q--)
    {
        solve();
    }
    return 0;
}