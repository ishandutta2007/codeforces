#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
const ll mo = 998244353;
const ld eps = 1e-9;
ll t, n;
string s;
map<string, ll> me;
vector<string> isi;
void hai(string s)
{
    if(me[s])return ;
    me[s] = 1;
    isi.pb(s);
    for(ll i = 0; i + 2 < n; i++)
        if(s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0')
        {
            swap(s[i], s[i + 2]);
            hai(s);
            swap(s[i], s[i + 2]);
        }
    for(ll i = 2; i < n; i++)
        if(s[i] == '1' && s[i - 1] == '1' && s[i - 2] == '0')
        {
            swap(s[i], s[i - 2]);
            hai(s);
            swap(s[i], s[i - 2]);
        }
}
ll f[NN];
ll fi[NN];
ll com(ll A, ll B)
{
    return (f[A] * ((fi[B] * fi[A - B]) % mo)) % mo;
}
ll powo(ll A, ll B)
{
    if(B == 0)
        return 1;
    else
    {
        ll tmp = powo(A, B / 2);
        tmp = (tmp * tmp) % mo;
        if(B % 2 == 1)
            tmp = (tmp * A) % mo;
        return tmp;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    f[0] = 1;
    // cout << powo(2, 10) << "_\m";''
    for(ll i = 1; i <= 100000; i++)
        f[i] = (f[i - 1] * i) % mo;
    // fi[100000] = powo(f[100000], mo - 2); 
    // for(ll i = (100000 - 1); i > 0; i--)
    fi[0] = 1;
    for(ll i = 1; i <= 100000; i++)
    {
        // fi[i] = (fi[i + 1] * i) % mo;
        fi[i] = (fi[i - 1] * powo(i, mo - 2)) % mo;
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        cin >> s;
        me.clear();
        isi.clear();
        ll byk = 0;
        ll nol = 0;
        vector<ll> ff;
        ll zz[2];
        zz[0] = 0;
        zz[1] = 0;
        for(ll i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                // cout << i % 2 << ", ";
                zz[i % 2]++;
                ff.pb(i);
            }
            nol += (s[i] == '0');
            byk += (s[i] == '1');
        }
        // cout << "\n";
        ll jer = 0;
        // if(ff[0] % 2 != 0)
            // jer++;
        // if(ff.back() % 2 == n % 2)
            // jer++;
        // cout << zz[0] << " " << zz[1] << "___\n";
        // cout << min(zz[0], zz[1]) << "_\n";
        jer = 0;
        // for(ll i = 1; i < ff.size(); i++)
        //     if((ff[i - 1] % 2) == (ff[i] % 2))
        //         jer++;
        // cout << n - nol + jer << " " << nol << "\n";
        ll X = nol;
        ll lst = 0;
        for(ll i = 0; i < ff.size(); i++)
        {
            if((ff[i] % 2) != (lst % 2))
                lst++;
            lst++;
        }
        // lst--;
        // cout << lst << "  ";
        X += (n - lst) / 2;
        // cout << X << " " << nol << "_\n";
        cout << com(X, nol) << "\n";
        continue;
        // hai(s);
        // sort(isi.begin(), isi.end());
        // cout << isi.size() << "\n";
        // cout << "_\n";
        // for(ll i = 0; i < (1 << n); i++)
        // {
        //     string f;
        //     for(ll j = 0; j < n; j++)
        //         if(i & (1 << j))
        //             f += "1";
        //         else
        //             f += "0";
        //     // reverse(f.begin(), f.end());
        //     // if(__builtin_popcount(i) == byk)
        //         // cout << f << " " << me[f] << "\n";                    
        // }
        // // continue;
        // for(ll i = 0; i < isi.size(); i++)
        // {
        //     string zz = isi[i];
        //     cout << isi[i] << "   ";
        //     for(ll j = 0; j < n; j++)
        //         if(zz[j] == '0')
        //             cout << j % 2 << ", ";
        //     cout << "\n";
        //     // reverse(zz.begin(), zz.end());
        //     // cout << me[zz];
        // }
    }
}