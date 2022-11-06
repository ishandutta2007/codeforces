#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, a[NN], z[NN], b[NN];
void gagal()
{
    cout << "NO\n";
    exit(0);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 1; i < n; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        if(tb < n)
            gagal();
        a[i] = ta;
    }
    sort(a + 1, a + n);
    for(ll i = 1; i < n; i++)
    {
        z[i] = i;
        if(i > a[i])
            gagal();
    }
    z[n] = n;
    a[n] = n;
    // for(ll i = 1; i <= n; i++)
        // cout << i << " " << a[i] << "\n";
    ll kiri = 1;
    for(ll i = 1; i <= n; i++)
    {
        ll nx = i;
        while(nx < n && a[nx + 1] == a[i])
            nx++;
        b[a[i]] = 1;
        z[i] = a[i];
        for(ll j = i + 1; j <= nx; j++)
        {
            while(kiri < a[i] && b[kiri])
                kiri++;
            // cout << i << " " <<  j << " " << kiri << "\n";
            if(kiri == a[i])
                gagal();
            b[kiri] = 1;
            z[j] = kiri;
        }
        // reverse(z + i, z + nx + 1);
        i = nx;
    }
    cout << "YES\n";
    for(ll i = 1; i < n; i++)
        cout << z[i] << " " << z[i + 1] << "\n";
}