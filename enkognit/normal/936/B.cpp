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

ll n, m, k, j, o, l, r, s;
ll a[500001];
vector <ll> c[100002], ans;
bool fl1=0, fl2=0;
bool t[100002][2];
bool tt[100002], u[100002];

void df(ll h)
{
    u[h]=1;
    tt[h]=1;
    //cout << fl1 << "\n";
    for (int i = 0; i < c[h].size(); i++)
        if (u[c[h][i]])  {fl1=1;return;} else
        if (!tt[c[h][i]])
        {
            df(c[h][i]);
            if (fl1) {return;}
        }
    u[h]=0;
}

void dfs(ll h)
{
    l++;
    a[l]=h;
    t[h][l%2]=1;
    if (c[h].size()==0 && l%2==0) {cout << "Win\n";for (int i = 1; i <= l; i++) cout << a[i] << " ";exit(0);}
    for (int i = 0; i < c[h].size(); i++)
        if (!t[c[h][i]][(l+1)%2])
        {
            dfs(c[h][i]);
        }
    l--;
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        ll x;
        cin >> x;
        for (int j = 0; j < x; j++)
        {
            ll p;
            cin >> p;
            c[i].pb(p);
        }
    }
    cin >> s;
    df(s);
    dfs(s);
    if (fl1) cout << "Draw\n"; else cout << "Lose\n";
    return 0;
}
/*

*/