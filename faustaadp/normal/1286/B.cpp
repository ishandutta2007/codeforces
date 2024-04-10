#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 2e3 + 5;
ll n, i, p[NN], a[NN], jaw[NN], R, ketemu;
vector<ll> v[NN];
void dfs(ll pos)
{
    if(ketemu)
        return;
    if(a[pos] == 0)
    {
        ketemu = pos;
        return ;
    }
    for(ll i = 0; i < v[pos].size(); i++)
        dfs(v[pos][i]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
    {
        ll ta, tb;
        cin >> p[i] >> a[i];
        if(p[i] == 0)
            R = i;
        else
            v[p[i]].pb(i);
    }
    for(ll i = 1; i <= n; i++)
    {
        ketemu = 0;
        dfs(R);
        if(ketemu == 0)
        {
            cout << "NO\n";
            return 0;
        }
        jaw[ketemu] = i;
        while(ketemu)
        {
            a[ketemu]--;
            ketemu = p[ketemu]; 
        }
    }
    cout << "YES\n";
    for(ll i = 1; i <= n; i++)
        cout << jaw[i] << " ";
    cout << "\n";
}