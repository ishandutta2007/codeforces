#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[300001];
string s, t;
vector <ll> v[1000], c[200001];
ll tt[1000001];

void dfs(ll h,ll k,ll pr)
{
    tt[h]=k;
    //cout << h << "\n";
    for (int i = 0; i < c[h].size(); i++)
            if (c[h][i]!=pr)
            {
                if (tt[c[h][i]]>0)
                {
                    {
                        ans=min(ans,abs(tt[h]-tt[c[h][i]])+1);

                        //cout << v[p][i] << " " << h << "\n";
                        //cout << tt[h] << " " << tt[v[p][i]] << "\n";
                    }
                }else dfs(c[h][i],k+1,h);
            }
    tt[h]=0;
}

int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    //if (n>200) {cout << 3;exit(0);}
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        ll z=a[i], p=1;
        while (z)
        {
            if (z%2) v[p].pb(i);
            if (v[p].size()>2)
            {
                cout << "3";
                exit(0);
            }
            z/=2;
            p++;
        }
    }
    for (int i = 1; i <= 500; i++)
    {
        if (v[i].size()>1)
        {
            c[v[i][0]].pb(v[i][1]);
            c[v[i][1]].pb(v[i][0]);
        }
    }
    for (int i = 1; i <= n; i++)dfs(i,1,0);
    if (ans==1e18) cout << -1; else cout << ans;
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