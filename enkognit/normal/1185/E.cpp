#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second
#define mp make_pair

using namespace std;

ll n, m, i, j, k, t;
vector <ll> v, q;
pair<pll,pll> w[30];
bool tt[300001];
string s[3002], d[3002];


int main()
{
    ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    cin >> t;
    //cout << 'z'-'a' << "\n";
    while (t--)
    {
        cin >> n >> m;
        ll p=0, mx=-1;
        for (int i = 0; i <= 26; i++)
            w[i]=mp(mp(0,0),mp(0,0));
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            d[i]=s[i];
            s[i]=' '+s[i];
            for (int j = 1; j <= m; j++)
            {
                d[i][j]='.';
                if (s[i][j]>='a' && s[i][j]<='z')
                {
                    mx=max(mx,(ll)s[i][j]-(ll)'a');
                    if (w[s[i][j]-'a'].fi.fi==0)
                    {
                        w[s[i][j]-'a'].fi=mp(i,j);
                    }
                    w[s[i][j]-'a'].se.fi=i;
                    w[s[i][j]-'a'].se.se=j;
                }
            }
        }
        bool z=1;
        for (int it = 0; it < 26; it++)
        {
            if (w[it].fi.fi!=w[it].se.fi && w[it].fi.se!=w[it].se.se) {z=0;break;}
            for (int i = w[it].fi.fi; i <= w[it].se.fi; i++)
                for (int j = w[it].fi.se; j <= w[it].se.se; j++)
                {
                    d[i][j]=it+'a';
                }
        }
        if (!z){cout << "NO\n";continue;}
        bool tt=1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (s[i][j]!=d[i][j]) {tt=0;}
                //cout << d[i][j];
            }
            //cout << "\n";
        }
        if (!tt) {cout << "NO\n";}else
        {
            cout << "YES\n";
            cout << mx+1 << "\n";
            for (int i = 0; i <= mx; i++)
                if (w[i].fi.fi)
                {
                    cout << w[i].fi.fi << " " << w[i].fi.se << " " << w[i].se.fi << " " << w[i].se.se << "\n";
                }else
                cout << w[mx].fi.fi << " " << w[mx].fi.se << " " << w[mx].se.fi << " " << w[mx].se.se << "\n";
        }
    }



}