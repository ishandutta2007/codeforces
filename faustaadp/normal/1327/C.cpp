#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n, m, k, x, y, te;
ll X[404040], Y[404040], awal;
string s;
string hai(ll aa, ll bb)
{
    if(X[aa] + 1 == X[bb]) return "D";
    if(X[aa] - 1 == X[bb]) return "U";
    if(Y[aa] + 1 == Y[bb]) return "R";
    if(Y[aa] - 1 == Y[bb]) return "L";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m >> k;
    for(ll i = 1; i <= n; i++)
    {
        if(i % 2 == 1)
        {
            for(ll j = 1; j <= m; j++)
            {
                te++;
                X[te] = i;
                Y[te] = j;
            }
        }
        else
        {
            for(ll j = m; j >= 1; j--)
            {
                te++;
                X[te] = i;
                Y[te] = j;
            }
        }
    }
    // return 0;
    for(ll i = 1; i <= k * 2; i++)
        cin >> x >> y;
    for(ll i = 1; i < n;i ++)
        s += "U";
    for(ll i = 1; i < m;i ++)
        s += "L";
    for(ll i = 1; i <(n * m) ;i++)
        s += hai(i, i + 1);
    if(s.length() == 0)
        s = "D";
    cout << s.length() << "\n";
    cout << s << "\n";
}