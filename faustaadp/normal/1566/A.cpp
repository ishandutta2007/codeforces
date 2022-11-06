#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld; 
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll n, s;
        cin >> n >> s;
        ll kir = n / 2 + 1;
        ll has = s / kir;
        cout << has << "\n";
    }
}