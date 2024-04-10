#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define fr front()
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, k, s;
queue <ll> q;
vector <ll> c[100001];
bool t[100001];

int main()
{
    //ios_base::sync_with_stdio(0);
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
    ll ans=0, o=0;
    for (int i = 1; i <= n; i++)
        if (!t[i])
        {
            o++;
            queue<ll> q;
            q.push(i);
            ll k=0;
            while (!q.empty())
            {
                ll x=q.fr;
                q.pop();
                if (t[x]) continue;
                //cout << x << " " << o << "\n";
                t[x]=1;k++;
                for (int i = 0; i < c[x].size(); i++)
                    if (!t[c[x][i]])
                    {
                        q.push(c[x][i]);
                    }
            }
            ans+=max(k-1,0ll);
        }
    cout << (ll)pow(2,ans);
    return 0;
}