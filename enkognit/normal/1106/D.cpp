#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, j, k, l, r, kol, ans;
vector <ll> c[200001], v;
bool t[100001];
set <ll> s;

int main()
{
    ios_base::sync_with_stdio(0);
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
    s.insert(1);
    while (s.size())
    {
        ll x=*s.begin();
        t[x]=1;
        s.erase(s.begin());
        v.pb(x);
        for (int i = 0; i < c[x].size(); i++)
            if (!t[c[x][i]]) s.insert(c[x][i]);
    }
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    return 0;
}
/*
7 2
1 1 1 1 1 3 3
1 2 3 3 1 1
*/