#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, h, m, k;
vector<pair<ll, ll> > v;
vector<ll> z;
ll cek(ll R)
{
    R--;
    ll L = R - k + 2;
    while(L < 0)
    {
        L += (m / 2);
        R += (m / 2);
    } 
    ll X = 2 * n, Y = -1;
    ll kir = 0;
    ll kan = 2 * n - 1;
    while(kir <= kan)
    {
        ll ten = (kir + kan) / 2;
        if(L <= z[ten])
        {
            X = ten;
            kan = ten - 1;
        }
        else
            kir = ten + 1;
    }
    kir = 0;
    kan = 2 * n - 1;
    while(kir <= kan)
    {
        ll ten = (kir + kan) / 2;
        if(z[ten] <= R)
        {
            Y = ten;
            kir = ten + 1;
        }
        else
            kan = ten - 1;
    }
    // cout << L << " " << R << " () " << X << " " << Y << "_\n";
    // cout << Y - X + 1 << "!@\n";
    return (Y - X + 1);
}
void jaw(ll R)
{
    R--;
    ll L = R - k + 2;
    while(L < 0)
    {
        L += (m / 2);
        R += (m / 2);
    } 
    for(ll i = 0; i < n * 2; i++)
        if(L <= v[i].fi && v[i].fi <= R)
            cout << v[i].se << " ";
    cout << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> h >> m >> k;
    for(ll i = 1; i <= n; i++)
    {
        ll ta;
        cin >> ta;
        cin >> ta;
        v.pb(mp(ta % (m / 2), i));
        v.pb(mp(ta % (m / 2) + (m / 2), i));
        z.pb(ta % (m / 2));
        z.pb(ta % (m / 2) + (m / 2));
    }
    sort(v.begin(), v.end());
    sort(z.begin(), z.end());
    ll has = 1e18;
    ll t = -1;
    for(ll i = 0; i < n; i++)
    {
        ll hz = cek((v[i].fi + k) % (m / 2));
        if(hz < has)
        {
            has = hz;
            t = (v[i].fi + k) % (m / 2);
        }
    }  
    for(ll i = 0; i < n; i++)
    {
        ll hz = cek((v[i].fi) % (m / 2));
        if(hz < has)
        {
            has = hz;
            t = (v[i].fi + k) % (m / 2);
        }
    }  
    for(ll i = 0; i < n; i++)
    {
        ll hz = cek((v[i].fi + (m / 2) - k) % (m / 2));
        if(hz < has)
        {
            has = hz;
            t = (v[i].fi + k) % (m / 2);
        }
    }  
    cout << has << " " << t << "\n";  
    jaw(t);
}