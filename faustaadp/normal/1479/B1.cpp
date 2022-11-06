#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 2e5 + 5;
const int mo = 1e9 + 7;
ll n, a[NN], has;
vector<pair<ll, ll> > isi;
vector<ll> isi2;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cin >> a[i];
    for(ll i = 1; i <= n; i++)
    {
        ll jum = 0, nx = n;
        for(ll j = i; j <= n; j++)
        {
            if(a[j] != a[i])
            {
                nx = j - 1; 
                break;
            }
            jum++;
        }
        // cout << a[i] << " " << jum << "\n";
        isi.pb(mp(a[i], min(2LL, jum)));
        i = nx;
    }
    vector<ll> isi2;
    for(ll i = 0; i < isi.size(); i++)
    {
        has += isi[i].se;
        if(isi[i].se == 2)
            isi2.pb(i);
    }
    for(ll i = 1; i < isi2.size(); i++)
    {
        ll L = isi2[i - 1];
        ll R = isi2[i];
        // cout << L << " " << R << "@\n";
        if(isi[L].fi == isi[R].fi)
        {
            ll tmp = isi[L].fi;
            ll ban = 0;
            ll len = 0;
            // cout << isi[L].fi << "@\n";
            for(ll j = L + 1; j < R; j++)
            {
                len++;
                // cout << "_ " << isi[j].fi << "@@@\n";
                if(isi[j].fi == tmp)
                    ban++;
            }
            // cout << len << " " << ban << "@\n";
            if(((len % 2) == 1) && (ban * 2 + 1 == len))
                has--;
        }
    }
    cout << has << "\n";
}