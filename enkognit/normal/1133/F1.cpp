#include <bits/stdc++.h>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ld PI=3.14159265359, sec_clock=1e8;

ll n, m, l, r, k, h, i, j, T, ans;
//ll a[500001], b[500001];
vector <ll> c[500001];
bool t[500001];
string s,d;
queue<ll> q;

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    //ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    ll k=1;
    for (int i = 2; i <= n; i++) if (c[k].size()<c[i].size()) k=i;
    t[k]=1;
    q.push(k);
    //system("pause");
    while (!q.empty())
    {
        ll h=q.fr;
        q.pop();
        for (int i = 0; i < c[h].size(); i++)
            if (!t[c[h][i]])
            {
                cout << h << " " << c[h][i] << "\n";
                t[c[h][i]]=1;
                q.push(c[h][i]);
            }
    }
    //system("pause");
    return 0;
}