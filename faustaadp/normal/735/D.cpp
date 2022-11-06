#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
ll n, a[NN], b[NN], k, c[NN], has;
vector<pair<ll, ll> > isi, isi2;
ll prima(ll aa)
{
    if(aa == 1)
        return 0;
    for(ll i = 2; i * i <= aa; i++)
        if(aa % i == 0)
            return 0;
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    if(prima(n))
        cout << 1 << "\n";
    else
    if(n % 2 == 0)
        cout << 2 << "\n";
    else
    if(prima(n - 2))
        cout << 2 << "\n";
    else
        cout << 3 << "\n";
}