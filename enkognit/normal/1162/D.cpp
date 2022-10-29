#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, l, r, x, h, y, ans, k, z, gr[100001];
ll t[200001];
string s, d;
vector <pll> c[100001];

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    cin >> n >> k;
    gr[1]=(n+1)/2;
    for (int i = 2; i <= n; i++)
    {
        gr[i]=gr[i-1]+1;
        gr[i]-=n;
    }
    for (int i = 0; i < k; i++)
    {
        ll x, y;
        cin >> x >> y;
        ll px=0, py=0;
        ll rx=x-1, ny=y-rx, ry=y-1, nx=x-ry;
        if (ny<1) ny+=n;
        if (nx<1) nx+=n;
        px=ny-1;
        py=nx-1;
        c[x].pb(mp(px,y));
        c[y].pb(mp(py,x));
    }
    ll p=sqrt(n);
    for (int i = 1; i <= n; i++) sort(c[i].begin(),c[i].end());
    //for (int i = 0; i < c[3].size(); i++)
    //    cout << c[3][i].se << " ";
   // cout << "\n";
   // for (int i = 0; i < c[7].size(); i++)
   //     cout << c[7][i].se << " ";
    //cout << "\n";
    for (int it = 1; it <= p; it++)
        if (n%it==0)
        {
            bool tt=1;
            //cout << it << ": \n";
            for (ll i = 1; i <= n; i++)
            {
                ll o=i+it;
                //cout << " " << i << " " << o << "\n";
                if (o>n)o-=n;
                if (c[o].size()!=c[i].size()) {tt=0;break;}
                for (ll j = 0; j < c[i].size(); j++)
                {
                    ll p1=min(n-max(c[i][j].se,i)+min(i,c[i][j].se),max(c[i][j].se,i)-min(c[i][j].se,i));
                        ll p2=min(n-max(c[o][j].se,o)+min(o,c[o][j].se),max(c[o][j].se,o)-min(c[o][j].se,o));
                    if (p1!=p2) {tt=0;break;}
                }
                if (!tt) break;
            }
            if (tt) {cout << "Yes\n";exit(0);}

            //cout << n/it << ": \n";
            if (it>1)
            {tt=1;for (ll i = 1; i <= n; i++)
            {
                ll o=i+n/it;
                //cout << " " << i << " " << o << "\n";
                if (o>n)o-=n;
                if (c[o].size()!=c[i].size()) {tt=0;break;}
                    for (ll j = 0; j < c[i].size(); j++)
                    {
                        ll p1=min(n-max(c[i][j].se,i)+min(i,c[i][j].se),max(c[i][j].se,i)-min(c[i][j].se,i));
                        ll p2=min(n-max(c[o][j].se,o)+min(o,c[o][j].se),max(c[o][j].se,o)-min(c[o][j].se,o));
                        if (p1!=p2) {tt=0;break;}
                    }
                    if (!tt) break;

                }
                if (tt) {cout << "Yes\n";exit(0);}
            }
        }

    cout << "No\n";
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/