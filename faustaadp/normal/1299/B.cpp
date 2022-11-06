#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll n, i, a[NN], b[NN], x[NN], X[NN], Y[NN];
ll jar(ll aa,ll bb,ll cc,ll dd)
{
    return (cc - aa)*(cc - aa) + (dd - bb)*(dd - bb);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    for(ll i = 0;i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    if(n % 2 == 1)
    {
        cout << "NO\n";
    }
    else
    {
        for(ll i = 0; i < n; i++)
        {
            x[i] = jar(a[i], b[i], a[(i + 1) % n], b[(i + 1) % n]);
            X[i] = a[i] - a[(i + 1) % n];
            Y[i] = b[i] - b[(i + 1) % n];
        }
        for(ll i = 0; i < n; i++)
        {
            if(x[i] != x[(i + n / 2) % n])
            {
                cout << "NO\n";
                return 0;
            }
            if(X[i] * Y[(i + n / 2) % n] != X[(i + n / 2) % n] * Y[i])
            {
                cout << "NO\n";
                return 0;
            }
        }
        cout << "YES\n";
    }
}