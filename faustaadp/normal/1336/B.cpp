#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, n[3], has, x[3][202020];
void ceka(ll aa, ll bb, ll cc)
{
    // cout << aa << " " << bb << " " << cc << "\n";
    ll H = (aa - bb) * (aa - bb)
    + (aa - cc) * (aa - cc) +
    (cc - bb) * (cc - bb); 
    if(has == -1)
        has = H;
    has = min(has, H);
}
void cek(ll aa, ll bb, ll cc)
{
    ll L, R, C, kir, kan;
    L = 1, R = n[aa], kir = x[aa][1];
    while(L <= R)
    {
        C = (L + R) / 2;
        if(x[aa][C] <= cc)
        {
            kir = x[aa][C];
            L = C + 1;
        }
        else
            R = C - 1;
    }
    L = 1, R = n[bb], kan = x[bb][n[bb]];
    while(L <= R)
    {
        C = (L + R) / 2;
        if(x[bb][C] >= cc)
        {
            kan = x[bb][C];
            R = C - 1;
        }
        else
            L = C + 1;
    }
    // cout << aa << " " << bb << ":\n";
    ceka(kir, kan, cc);
    // cout << ""
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        vector<pair<ll, ll> > v;
        cin >> n[0] >> n[1] >> n[2];
        for(ll i = 0; i < 3; i++)
            for(ll j = 1; j <= n[i]; j++)
            {
                cin >> x[i][j];
                // cout << i << " " << j << " " << x[i][j] << " |||\n";
            }
        for(ll i = 0; i < 3; i++)
            sort(x[i] + 1, x[i] + 1 + n[i]);
        has = -1;
        for(ll i = 0; i < 3; i++)
            for(ll j = 1; j <= n[i]; j++)
            {
                if(i == 0)
                {
                    cek(1, 2, x[i][j]);
                    cek(2, 1, x[i][j]);
                }
                else
                if(i == 1)
                {
                    cek(0, 2, x[i][j]);
                    cek(2, 0, x[i][j]);
                }
                else
                {
                    cek(1, 0, x[i][j]);
                    cek(0, 1, x[i][j]);
                }
            }
        cout << has << "\n";
    }
}