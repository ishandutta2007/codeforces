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

ll n, m, k, j, l, r, p, v[101], ans[101];
pll pos[101];
string s[1002];
queue <pll> q[10],g[10];
map<char,ll> c;
ll w[1002][1002];
bool t[1002][1002];

void add(ll x,ll y,ll tt)
{
    //cout << x << " " << y << " " << tt << "\n";
    if (x<0 || y<0 || x>=n || y>=m || t[x][y]==1 || (s[x][y]!='.' && s[x][y]!=tt+48)) return;
    t[x][y]=1;
    w[x][y]=tt;
    //cout << x << " " << y <<" " << tt << " " << w[x][y][tt] << "\n";
    q[tt].push(mp(x,y));
}

int main()
{
	//freopen("unionday.in", "r", stdin);
	//freopen("unionday.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	cin >> n >> m >> p;
	for (int i = 1; i <= p; i++) cin >> v[i];
	v[0]=1;
	for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        for (int j = 0; j < m; j++)
        {
            w[i][j]=0;
            if (s[i][j]!='.' && s[i][j]!='#') add(i,j,s[i][j]-48);
        }
    }
    //cout << pos[2].se;
    ll z=0,tt=0;
    while (z<p)
    {
        tt++;
        if (tt>p) tt=1;
        if (q[tt].empty()) {z++;continue;} else z=0;
        ll u=0;
        while (u<v[tt] && !q[tt].empty())
        {
            u++;
            ll o=q[tt].size();
            for (int i = 0; i < o; i++)
            {
                ll x=q[tt].fr.fi,y=q[tt].fr.se;
                q[tt].pop();
                add(x+1,y,tt);
                add(x-1,y,tt);
                add(x,y+1,tt);
                add(x,y-1,tt);
            }
        }
        /*for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                if (w[i][j]>0) cout << w[i][j]; else
                cout << s[i][j];
            cout << "\n";
        }*/
    }
    /*for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)cout << w[i][j][2] << " ";
        cout << "\n";
    }*/
    for (int i = 0; i < n; i++)
     for (int j = 0; j < m; j++)
     {
        ans[w[i][j]]++;
     }
    for (int i = 1; i <= p; i++) cout << ans[i] << " ";

    return 0;
}