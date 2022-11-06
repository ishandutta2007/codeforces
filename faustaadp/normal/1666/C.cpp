#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
const ll mo = 1e9 + 7;
pair<ll, ll> A[4];
vector<pair<pll, pll> > isi;
void buat(ll X1, ll Y1, ll X2, ll Y2)
{
    // cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << "@\n";
    if(X2 < X1)swap(X1, X2);
    if(Y2 < Y1)swap(Y1, Y2);
    if(X1 == X2 && Y1 == Y2)return ;
    isi.pb(mp(mp(X1, Y1), mp(X2, Y2)));
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    for(ll i = 1; i <= 3; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        A[i] = mp(ta, tb);
    }
    sort(A + 1, A + 1 + 3);
    buat(A[2].fi, min(A[3].se, min(A[1].se, A[2].se)), A[2].fi, max(A[3].se, max(A[1].se, A[2].se)));
    buat(A[1].fi, A[1].se, A[2].fi, A[1].se);
    buat(A[2].fi, A[3].se, A[3].fi, A[3].se);
    cout << isi.size() << "\n";
    for(auto z : isi)
        cout << z.fi.fi << " " << z.fi.se << " " << z.se.fi << " " << z.se.se << "\n";
}