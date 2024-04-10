#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 4e5 + 5;
const ll mo = 1e9 + 7;
ll TC;
string s;
ll n;
ll d[12][2][2];
ll b[12][2][2];
ll depe(ll pos, ll a1, ll a2)
{
    ll &ret = d[pos][a1][a2];
    if(pos < 0)
    {
        return (a1 == 0 && a2 == 0);
    }
    if(b[pos][a1][a2] != TC)
    {
        ret = 0;
        b[pos][a1][a2] = TC;
        for(ll i = 0; i <= 9; i++)
            for(ll j = 0; j <= 9; j++)
            {
                ll jum = i + j + a2;
                if((jum % 10) == (s[pos] - '0'))
                {
                    ret += depe(pos - 1, jum / 10, a1);
                    // cout << " " << i << " " << j << " " << a2 << " " << pos << " " << depe(pos - 1, jum / 10, a1) << "__\n";
                }
            }
        // cout << pos << " " << a1 << " " << a2 << " " << ret << "\n";
    }
    return ret;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        TC++;
        cin >> s;
        n = s.length();
        cout << depe(n - 1, 0, 0) - 2<< "\n";
    }
}