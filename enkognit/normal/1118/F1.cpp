#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, j, o, l, r, x, y, ans=0, b[1000001];
pll a[1000001];
bool t[1000001];
vector <ll> c[1000001];
set<ll> s;

void dfs(ll h)
{
    t[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (!t[c[h][i]])
        {
            dfs(c[h][i]);
            a[h].fi+=a[c[h][i]].fi;
            a[h].se+=a[c[h][i]].se;
        }
    a[h].fi+=(b[h]==1);
    a[h].se+=(b[h]==2);
    if (h!=1 && ((a[h].fi==0 && a[h].se==l)||(a[h].fi==r && a[h].se==0))) {ans++;}
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {ll x;cin >> x;b[i]=x;if (x==2) l++; else if (x==1) r++;}
    for (int i = 0; i < n-1; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    dfs(1);
    cout << ans;
    return 0;
}