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

ll n, m, k, q, p, ans, l, r, i, j, x, y, a[500001], b[11][11][11];
vector <ll> c[300001];
vector <ll> v;
ll d[1000001];
bool t[1000001];
string s;

int main()
{
    //freopen("redistricting.in","r",stdin);
    //freopen("redistricting.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    for (int x = 0; x < 10; x++)
        for (int y = 0; y < 10; y++)
            for (int z = 0; z < 10; z++)
            {
                bool t[11]={};
                vector <pll> v;
                ll o=0, p=0, l=y, r=x;
                while (!t[p])
                {
                    v.pb(mp(p,o));
                    t[p]=1;
                    p+=r;
                    o++;
                    p%=10;
                }
                v.pb(mp(p,o));
                ll mn=1e10;
                for (int j = 0; j < v.size(); j++)
                {
                    bool tt[11]={};
                    ll p=v[j].fi, q=1e10;
                    while (!tt[p])
                    {
                        if (p==z) {q-=1e10;break;}
                        tt[p]=1;
                        q++;
                        p+=l;
                        p%=10;
                    }
                    //if (l==0 && v[j].se==0) q++;
                    ll u=q+v[j].se-1;
                    if (u>-1 && u<1e10)
                    mn=min(mn,u);
                }
                b[x][y][z]=mn;
                //if (b[x][y][z]<0) cout << "----\n";
                if (x>y)
                {
                    p=min(b[x][y][z],b[y][x][z]);
                    b[x][y][z]=p;
                    b[y][x][z]=p;
                }
            }
    //cout << b[5][2][0] << "\n";
    for (int x = 0; x < 10; x++)
    {
        for (int y = 0; y < 10; y++)
        {
            ll ans=0;
            for (int i = 0; i < s.size()-1; i++)
            {
                ll p=s[i+1]-s[i];
                if (p<0) p+=10;
                ans+=b[x][y][p];
            }
            if (ans>=1e10 || ans<0) cout << "-1 "; else
            cout << ans << " ";
        }
        cout << "\n";
    }
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/