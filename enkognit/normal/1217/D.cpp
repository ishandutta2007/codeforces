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

ll n, k, l, m, r, i, j, x, y, ans;
bool b[5001];
bool tt[5001], t=0, w[5001];
vector <int> c[5001];
string s;

void dfs(int h)
{
    if (t) return;
    tt[h]=1;
    w[h]=1;
    for (int i = 0; i < c[h].size(); i++)
        if (tt[c[h][i]]){
    {
        cout << "2\n";
        for (int j = 0; j < m; j++) cout << b[j]+1 << " ";
    }
    exit(0);
    break;} else if (!w[c[h][i]])dfs(c[h][i]);
    tt[h]=0;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        ll x, y;
        cin >> x >> y;
        b[i]=(x<y);
        c[x].pb(y);
    }
    for (int i = 1; i <= n; i++) if (!w[i]) dfs(i);
    cout << "1\n";
    for (int i = 0; i < m; i++) cout << "1 ";
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/