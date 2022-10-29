#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair

using namespace std;

ll n, m, i, j, k;
vector <ll> v, c[300001];
bool tt[300001];
ll p[300001][21], kol[300001], rst[300001], lst[300001];

void dfs(ll h, ll w=0)
{
    lst[h]=h, p[h][0]=w, kol[h]=1;
    for (int i = 1; i < 20; i++) p[h][i]=p[p[h][i-1]][i-1];

    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=w)
        {
            rst[c[h][i]]=rst[h]+1;
            dfs(c[h][i],h);
            kol[h]+=kol[c[h][i]];
        }

    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=w && kol[c[h][i]]>kol[h]/2) lst[h]=lst[c[h][i]];
}

int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    rst[1]=0;
    dfs(1);
    cout << "d 1" << endl;
    ll dist, q=1;
    cin >> dist;
    while (1)
    {
        if (rst[q]==dist) {cout << "! " << q;exit(0);}
        q=lst[q];
        cout << "d " << q << endl;
        ll dst;
        cin >> dst;
        dst-=rst[q]+dist;
        dst=dst*(-1)/2;
        for (int i = 19; i > -1; i--)
            if (rst[q]-(1<<i)>=dst) q=p[q][i];
        if (rst[q]==dist) {cout << "! " << q;exit(0);}
        cout << "s " << q << endl;
        cin >> q;
    }
}