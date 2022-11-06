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
        ll k;
        cin >> s >> k;
        k--;
        n = s.length();
        vector<ll> jaw;
        ll sat = 1;
        for(ll i = n - 1; i >= 0; i--)
        {
            if((s[i] - '0') >= k)
            {
                s[i] -= k;
                for(ll j = 0; j < k; j++)
                    jaw.pb(sat);
                k = 0;
                break;
            }
            else
            {
                k -= (s[i] - '0');
                for(ll j = 0; j < (s[i] - '0'); j++)
                    jaw.pb(sat);
                s[i] = '0';
            }
            sat *= 10LL;
        }
        if(stoll(s) == 0)
        {
            k++;
            while(k > 0)
            {
                // cout << "_\n";
                ll len = jaw.size();
                // cout << len << "___\n";
                sort(jaw.begin(), jaw.end());
                for(ll i = 0; i < len; i++)
                {
                    if(jaw[i] == 1)
                        continue;
                    // cout << jaw[i] << "\n";
                    if(k <= 9)
                    {
                        ll tot = 0;
                        for(ll j = 0; j < k; j++)
                        {
                            tot += jaw[i] / 10;
                            jaw.pb(jaw[i] / 10);
                        }
                        jaw[i] -= tot;
                        k = 0;
                        break;
                    }
                    else
                    {
                        ll tot = 0;
                        for(ll j = 0; j < 9; j++)
                        {
                            tot += jaw[i] / 10;
                            jaw.pb(jaw[i] / 10);
                        }
                        jaw[i] -= tot;
                        k -= 9;
                        break;
                    }
                }    
            }
        }
        else
            jaw.pb(stoll(s));
        // cout << s << " " << k << "\n";
        for(auto isi : jaw)
            cout << isi << " ";
        cout << "\n";
    }
}