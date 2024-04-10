#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const int NN = 5e2 + 5;
const int mo = 1e9 + 7;
ll n, has;
ll tanya(ll aa)
{
    cout << "? " << aa << endl;
    ll ta;
    cin >> ta;
    return ta;
}
int main()
{
    // ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ll L = 1;
    ll R = n;
    while(L <= R)
    {
        ll C1 = L + (R - L) / 3;
        ll C2 = R - (R - L) / 3;
        // cout << L << " " << R << "\n";
        if(tanya(C1) < tanya(C2))
        {
            R = C2 - 1;
            has = C1;
        }
        else
        {
            L = C1 + 1;
            has = C2;
        }
    }
    cout << "! " << has << endl;
}