#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1e9+7;

ll n, i, j, m, ans, k, q, l, r, z;
ll a[500001], pr[50001];
vector <pll> v;
vector <vector<pll> > c;
map<ll,int> t;

int main()
{
    //freopen("robots.in","r",stdin);
    //freopen("robots.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {cin >> a[i];pr[i]=a[i]+pr[i-1];}
    c.pb(v);
    ll k=0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
        {
            //cout << j+1 << " " << i << "\n";
            //cout << pr[i]-pr[j] << "-" << t[pr[i]-pr[j]] << "\n";
            //system("pause");
            if (!t[pr[i]-pr[j]])
            {
                t[pr[i]-pr[j]]=c.size();
                c.pb(v);
                c[t[pr[i]-pr[j]]].pb(mp(j+1,i));
            }
             else
            {
                ll p=t[pr[i]-pr[j]];
                if (c[p][c[p].size()-1].se<=j) {c[p].pb(mp(j+1,i));}
            }
            if (c[t[pr[i]-pr[j]]].size()>c[t[k]].size()) k=pr[i]-pr[j];
        }
    cout << c[t[k]].size() << "\n";
    for (int i = 0; i < c[t[k]].size(); i++) cout << c[t[k]][i].fi << " " << c[t[k]][i].se << "\n";
    return 0;
}