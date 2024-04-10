#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fi first
#define se second
#define y1 Enkognit
#define all(v) v.begin(),v.end()

using namespace std;

ll n, T, kl = 0, m, ans, p, w;ll a[1000001];
vector<ll> c[100001];
vector<ll> v;
bool tt[1000001];
int tl[1000001];

void dfs(int h,int pp=-1)
{
    tt[h] = 1;
    T++;
    //cout << h << "\n";
    tl[h] = v.size();
    v.pb(h);
    if (T > 1e7)
    {
        return;
    }
    for (int i = 0; i < c[h].size(); i++)
        if (c[h][i]!=pp)
    {
        if (!tt[c[h][i]])
        {
            dfs(c[h][i],h);
        }
        else
        {
            if (tl[c[h][i]] != -1 && (v.size()==0 || c[h][i]!=v.back()))
            {
                //cout << h << " " << c[h][i] << "\n";
                if (v.size() - tl[c[h][i]] >= p)
                {
                    cout << "2\n";
                    cout << v.size() - tl[c[h][i]] << "\n";
                    for (int j = tl[c[h][i]]; j < v.size(); j++)
                        cout << v[j] << " ";
                    exit(0);
                }
            }
        }
        if (T > 1e7)
        {
            return;
        }
    }
    tl[h] = -1;
    v.pop_back();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    p = sqrt(n);
    if (p * p < n) p++;
    //cout << p << "\n";
    for (int i = 0; i < m; i++)
    {
        ll x=1, y=i+2;
        cin >> x >> y;
        c[x].pb(y);
        c[y].pb(x);
    }
    for (int i = 1; i <= n; i++) tl[i] = -1;
    dfs(1);
    //cout << "----\n";
    set<pair<int, int> > s;
    for (int i = 1; i <= n; i++)
    {
        a[i] = c[i].size();
        s.insert(mp(a[i], i));
    }
    for (int i = 1; i <= n; i++) tt[i] = 0;
    ll o = p;
    vector<ll> ans;
    while (ans.size()<p && s.size())
    {
        ll x = (*s.begin()).se;
        //cout << x << "\n";
        s.erase(s.begin());
        if (tt[x]) continue;
        //cout << x << " " << tt[x] << "\n";
        tt[x] = 1;
        //cout << x << " : ";
        ans.pb(x);
        for (int i = 0; i < c[x].size(); i++)
            if (!tt[c[x][i]])
            {
                //cout << c[x][i] << " ";
                tt[c[x][i]] = 1;
                s.erase(mp(a[c[x][i]], c[x][i]));
            }
        //cout << "\n";
    }
    cout << "1\n";
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << "\n";
        return 0;
}
/*
6
add 1
sum 1 1
add 3
add 1
sum 2 3
sum 1 2
*/