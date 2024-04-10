#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e6 + 5;
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n, g, b;
        cin >> n >> g >> b;
        ll jum = g + b;
        ll bth = n / 2 + n % 2;
        ll ban = (bth - 1)/ g;
        ll has = ban * jum + (bth - ban * g);
        has = max(has, n);
        cout << has << "\n";
    }
}