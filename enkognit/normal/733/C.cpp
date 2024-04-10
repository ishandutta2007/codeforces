#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, i, j, r, p, k, ans, a[10001], b[10001];
string s;
vector <ll> v;
map<int,int> g;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    ll u=0;
    for (int i = 0; i < n; i++)
    {cin >> a[i];u+=a[i];}
    cin >> m;
    for (int i = 0; i < m; i++) {cin >> b[i];u-=b[i];}
    if (u!=0){cout << "NO\n";exit(0);}
    ll j=0, o=-1;
    v.pb(o);
    for (int i = 0; i < n; i++)
    {
        g[a[i]]++;
        if (k<b[j] && k+a[i]>b[j]) {cout << "NO\n";exit(0);}
        k+=a[i];
        if (k==b[j])
        {
            if (g[a[i]]==i-o && i-o>1){cout << "NO\n";exit(0);}g={};k=0;o=i,j++;
            v.pb(o);
        }
    }
    cout << "YES\n";
    for (int p = v.size()-2; p > -1; p--)
    {
        if (v[p]+1==v[p+1]) continue;
        ll mx=0, l=0;
        for (int i = v[p]+1; i <= v[p+1]; i++)
        {
            if (mx<a[i]) mx=a[i];
        }
        ll u=-1;
        bool t=0;
        if (mx==a[v[p]+1] && a[v[p]+2]<mx) u=v[p]+1,t=1; else
        if (mx==a[v[p+1]] && a[v[p+1]-1]<mx) u=v[p+1],t=0; else
        for (int i = v[p]+2; i < v[p+1]; i++)
        {
            if (mx==a[i])
            {
                if (a[i+1]<mx) {t=1,u=i;break;}
                if (a[i-1]<mx) {t=0,u=i;break;}
            }
        }
        if (t)
        {
            for (int i = u+1; i <= v[p+1]; i++) cout << u+1 << " R\n";
            for (int i = u; i > v[p]+1; i--) cout << i+1 << " L\n";
        }else
        {
            cout << u+1 << " L\n";
            u--;
            for (int i = u+1; i < v[p+1]; i++) cout << u+1 << " R\n";
            for (int i = u; i > v[p]+1; i--) cout << i+1 << " L\n";
        }
    }

    return 0;
}