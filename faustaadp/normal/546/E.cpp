#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e3 + 5;
ll n, m, A[NN], B[NN];
vector<ll> v[NN];
ll cap[NN][NN], b[NN], S, T, par[NN];
void buat(ll aa, ll bb, ll cc)
{
    v[aa].pb(bb);
    v[bb].pb(aa);
    cap[aa][bb] += cc;
}
ll bfs()
{
    queue<ll> q;
    memset(b, 0, sizeof(b));
    b[S] = 1;
    q.push(S);
    while(!q.empty())
    {
        ll u = q.front();
        q.pop();
        if(u == T)
        {
            return 1;
        }
        for(ll i = 0; i < v[u].size(); i++)
        {
            ll nx = v[u][i];
            if(cap[u][nx] && b[nx] == 0)
            {
                par[nx] = u;
                b[nx] = 1;
                q.push(nx);
            }
        }
    }
    return 0;
}
ll upd(ll pos, ll mi)
{
    if(pos == S)
        return mi;
    else
    {
        ll tmp = upd(par[pos], min(mi, cap[par[pos]][pos]));
        cap[par[pos]][pos] -= tmp;
        cap[pos][par[pos]] += tmp;
        return tmp;
    }
}
ll mf()
{
    if(!bfs())
        return 0;
    return upd(T, 1e18);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m;
    S = n * 2 + 1;
    T = n * 2 + 2;
    ll asal = 0;
    ll tot = 0;
    for(ll i = 1; i <= n; i++)
    {
        cin >> A[i];
        asal += A[i];
    }
    for(ll i = 1; i <= n; i++)
    {
        cin >> B[i];
        tot += B[i];
    }
    for(ll i = 1; i <= n; i++)
        buat(S, i, A[i]);
    for(ll i = 1; i <= n; i++)
        buat(i + n, T, B[i]);
    for(ll i = 1; i <= n; i++)
        buat(i, i + n, A[i]);
    while(m--)
    {
        ll ta, tb;
        cin >> ta >> tb;
        buat(ta, tb + n, A[ta]);
        buat(tb, ta + n, A[tb]);
    }
    ll tem = 0;
    while(1)
    {
        ll hz = mf();
        if(!hz)
            break;
        tem += hz;
    }
    if(tem == tot && asal == tot)
    {
        cout << "YES\n";
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= n; j++)
            {
                cout << cap[j + n][i];
                if(j < n)
                    cout << " ";
                else
                    cout << "\n";
            }
    }
    else
        cout << "NO\n";
}