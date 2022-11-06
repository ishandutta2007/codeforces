#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e6 + 5;
int T, d[404][404][404];
string s, t;
ll n, m;
ll depe(ll pos, ll pos1, ll pos2)
{
    if(pos == n && pos2 == m)
        return pos1;
    if(pos == n)
        return -1e9;
    ll ret = d[pos][pos1][pos2];
    if(ret != -1)
        return ret;
    ret = depe(pos + 1, pos1, pos2);
    if(pos1 < m && s[pos] == t[pos1])ret = max(ret, depe(pos + 1, pos1 + 1, pos2));
    if(pos2 < m && s[pos] == t[pos2])ret = max(ret, depe(pos + 1, pos1, pos2 + 1));
    return d[pos][pos1][pos2] = ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--)
    {
        cin >> s;
        cin >> t;
        n = s.length();
        m = t.length();
        for(ll i = 0;i <= n; i++)
            for(ll j = 0; j <= m; j++)
                for(ll k = 0; k <= m; k++)
                    d[i][j][k] = -1;
        ll ya = 0;
        for(ll i = 0;i < m; i++)
        {
            // cout << i << " " << depe(0, 0, i) << "\n";
            if(depe(0, 0, i) >= i)
            {
                ya = 1;
                break;
            }
        }
        if(ya)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}