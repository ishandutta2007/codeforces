#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, t, sz;
ll a[202020];
ll b[202020];
ll c[202020];
ll d[404040];
ll nx[204040];
ll has;
void dfs(ll pos, ll idx)
{
    if(b[pos])
    {
        sz = idx;
        return ;
    }
    b[pos] = 1;
    d[idx] = pos;
    dfs(nx[pos], idx + 1);
}
void cek(ll aa)
{
    for(ll i = 0; i < sz; i++)
        d[i + sz] = d[i];
    for(ll i = 1; i <= sz; i++)
    {
        if((sz % i) == 0)
        {
            // cout << sz << " " << i << "_\n";
            for(ll j = 0; j < i; j++)
            {
                ll bisa = 1, lst = -1;
                for(ll k = j; k < (2 * sz); k += i)
                {
                    // cout << i << " " << j << " " << sz << " " << k << "\n";
                    if((lst != -1) && (c[d[k]] != lst))
                    {
                        bisa = 0;
                        break;
                    }
                    lst = c[d[k]];
                }
                // cout << i << " " << j << " " << bisa << "\n";
                if(bisa)
                    has = min(has, i);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        has = 1e18;
        cin >> n;
        for(ll i = 1; i <= n; i++)
            cin >> a[i];
        for(ll i = 1; i <= n; i++)
        {
            nx[a[i]] = a[a[i]];
            // cout << a[i] << "   " << nx[a[i]] << "\n";
        }
        for(ll i = 1; i <= n; i++)
            b[i] = 0;
        for(ll i = 1; i <= n; i++)
            cin >> c[i];
        for(ll i = 1; i <= n; i++)
            if(b[i] == 0)
            {
                dfs(i, 0);
                cek(i);
            }
        cout << has << "\n";
    }
}