#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll n, m, te, b[NN], aw[NN], ak[NN], te2;
vector<ll> v[NN];
ll cek(ll x)
{
    for(ll i = 1; i <= n; i++)
    {
        te++;
        for(ll j = 0; j < v[i].size(); j++)
        {
            te2++;
            b[v[i][j]] = te;
            aw[v[i][j]] = te2;
            b[(v[i][j] + i) % n] = te;
            ak[(v[i][j] + i) % n] = te2;
        }
        for(ll j = 0; j < v[i].size(); j++)
        {
            // cout << x << " " << v[i][j] << " " << (v[i][j] + x) % n << "\n"; 
            if(b[(v[i][j] + x) % n] != te)
                return 0;
            if(b[((v[i][j] + x + i)) % n] != te)
                return 0;
            if((aw[(v[i][j] + x) % n] != ak[((v[i][j] + x + i)) % n]) && (ak[(v[i][j] + x) % n] != aw[((v[i][j] + x + i)) % n]))
                return 0;
        }
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n >> m;
    for(ll i = 1; i <= m; i++)
    {
        ll ta, tb;
        cin >> ta >> tb;
        if(tb < ta)
            tb += n;
        if((tb - ta) * 2 > n)
        {
            swap(ta, tb);
            ta %= n;
            if(tb < ta)
                tb += n;
        }
        // cout << ta << " " << tb << "\n";
        v[(tb - ta)].pb(ta % n);
    }
    for(ll i = 1; i < n; i++)
        if(n % i == 0)
            if(cek(i))
            {
                cout << "Yes\n";
                return 0;
            }
    cout << "No\n";
}