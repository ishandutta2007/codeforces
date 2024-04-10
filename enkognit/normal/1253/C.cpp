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

ll n, m, k, l, r, i, j, kl, x, y, pr[1000001], a[2000001], c[1000001];
ld ans;
pll bn[200001][21];
map<int, int> tt;
string s;
vector <pll> v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a+1,a+n+1);
    for (int i = 1; i <= n; i++)
    {
        pr[i]=pr[max(0ll,i-m)]+a[i];
    }
    ll ans=0;
    for (int i = 1; i <= n; i++)
    {
        ans+=pr[i];
        cout << ans << " ";
    }
    return 0;
}