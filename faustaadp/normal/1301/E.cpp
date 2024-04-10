#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll t, n, m, q;
ll a[550][550];
ll x[550][550];
ll kan[550][550];
ll p[4][550][550];
ll P[550][550];
ll X1[303030];
ll X2[303030];
ll Y1[303030];
ll Y2[303030];
ll jaw[303030];
vector<pair<ll, pair<ll, ll> > > isi;
ll ban(ll aa, ll bb, ll cc, ll dd,ll ee)
{
    return p[ee][cc][dd] - p[ee][aa - 1][dd] - p[ee][cc][bb - 1] + p[ee][aa - 1][bb - 1];
}
ll cek(ll aa, ll bb, ll bsr)
{
    if((aa + bsr + bsr - 1) > n)return 0;
    if((bb + bsr + bsr - 1) > m)return 0;
    if(ban(aa, bb, aa + bsr - 1, bb + bsr - 1, 0) != (bsr * bsr))return 0;
    if(ban(aa, bb + bsr, aa + bsr - 1, bb + bsr + bsr - 1, 1) != (bsr * bsr))return 0;
    if(ban(aa + bsr, bb, aa + bsr + bsr - 1, bb + bsr - 1, 2) != (bsr * bsr))return 0;
    if(ban(aa + bsr, bb + bsr, aa + bsr + bsr - 1, bb + bsr + bsr - 1, 3) != (bsr * bsr))return 0;
    return 1;
}
void hai(ll aa)
{
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
            P[i][j] = P[i - 1][j] + P[i][j - 1] - P[i - 1][j - 1] + (x[i][j] == aa);
    ll kk = aa * 2 - 1;
    for(ll i = 1; i <= q; i++)
    {
        if((X1[i] > (X2[i] - kk)) || (Y1[i] > (Y2[i] - kk)))
            continue;
        if((P[X2[i] - kk][Y2[i] - kk] - P[X2[i] - kk][Y1[i] - 1] - P[X1[i] - 1][Y2[i] - kk] + P[X1[i] - 1][Y1[i] - 1]) > 0)
        {   
            // cout << aa << "   " << X1[i] << " " << Y1[i] << " " << X2[i] - kk << " " << Y2[i] - kk << "___\n";
            // cout << P[X2[i] - kk][Y2[i] - kk] << " " << P[X2[i] - kk][Y1[i] - 1] << " " << P[X1[i] - 1][Y2[i] - kk] << " " << P[X1[i] - 1][Y1[i] - 1] << "\n";
            jaw[i] = aa;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m >> q;
    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
        {
            char ct;
            cin >> ct;
            if(ct == 'R')a[i][j] = 0;
            if(ct == 'G')a[i][j] = 1;
            if(ct == 'Y')a[i][j] = 2;
            if(ct == 'B')a[i][j] = 3;
        }
    for(ll i = 1; i <= n; i++)
        for(ll j = m; j >= 1; j--)
        {
            if(a[i][j] == 0 && ((j == m) || (a[i][j + 1] != 0)))
                kan[i][j] = j;
            else
            if(a[i][j] == 0)
                kan[i][j] = kan[i][j + 1];
        }
    for(ll k = 0; k < 4; k++)
        for(ll i = 1; i <= n; i++)
            for(ll j = 1; j <= m; j++)
                p[k][i][j] = p[k][i - 1][j] + p[k][i][j - 1] - p[k][i - 1][j - 1] + (a[i][j] == k);

    ll K = 50;

    for(ll i = 1; i <= n; i++)
        for(ll j = 1; j <= m; j++)
        {
            ll mun = kan[i][j] - j + 1;
            if(cek(i, j, mun))
            {
                x[i][j] = mun;
                if(mun > K)
                    isi.pb(mp(mun, mp(i, j)));
            }
        }
    sort(isi.begin(), isi.end());
    ll sz = isi.size();
    for(ll i = 1; i <= q; i++)
        cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];
    for(ll i = 1; i <= K; i++)
        hai(i);
    for(ll i = 1; i <= q; i++)
        for(ll j = 0; j < sz; j++)
        {
            ll A1 = isi[j].se.fi;
            ll B1 = isi[j].se.se;
            ll A2 = A1 + isi[j].fi + isi[j].fi - 1;
            ll B2 = B1 + isi[j].fi + isi[j].fi - 1;
            // cout << A1 << " " << B1 << " " << A2 << " " << B2 << "\n";
            if(X1[i] <= A1 && A2 <= X2[i] && Y1[i] <= B1 && B2 <= Y2[i])
                jaw[i] = isi[j].fi;
        }
    for(ll i = 1; i <= q; i++)
    {
        jaw[i] *= 2;
        jaw[i] *= jaw[i];
        cout << jaw[i] << "\n";
    }

    // for(ll i = 1; i <= n; i++)
    // {
    //     for(ll j = 1; j <= m; j++)
    //         cout << x[i][j];
    //     cout << "\n";
    // }



}