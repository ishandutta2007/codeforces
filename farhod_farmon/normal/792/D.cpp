#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 100100;
const long long MX = 300300;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

ll n;
ll q;
ll l;
vector < ll > v;

void get(ll x, ll y, ll g)
{
        v.pb(x);
        if(x == y)
        {
                return;
        }
        if(x < y)
        {
                get(x + (1ll << g), y, g - 1);
        }
        else
        {
                get(x - (1ll << g), y, g - 1);
        }
}

void solve()
{
        cin >> n >> q;
        while((1ll << l + 1) <= n)
        {
                l++;
        }
        for(int i = 1; i <= q; i++)
        {
                ll x;
                string s;
                cin >> x >> s;
                v.clear();
                get(1ll << l, x, l - 1);
                for(int i = 0; i < s.size(); i++)
                {
                        if(s[i] == 'U')
                        {
                                if(v.size() == 1)
                                {
                                        continue;
                                }
                                v.pop_back();
                                continue;
                        }
                        if(v.size() == l + 1)
                        {
                                continue;
                        }
                        ll x = v.back();
                        ll g = l - (ll)v.size();
                        if(s[i] == 'L' && x - (1ll << g) > 0)
                        {
                                v.pb(x - (1ll << g));
                        }
                        if(s[i] == 'R' && x + (1ll << g) < n + 1)
                        {
                                v.pb(x + (1ll << g));
                        }
                }
                cout << v.back() << endl;
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("friendcross.in");
        //fout("friendcross.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}