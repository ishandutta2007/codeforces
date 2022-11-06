#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e5 + 5;
ll n, m, q;
string a[220];
string b[220];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(ll i = 0; i < n; i++)
        cin >> a[i];
    for(ll i = 0; i < m; i++)
        cin >> b[i];
    cin >> q;
    while(q--)
    {
        ll ta;
        cin >> ta;
        ta--;
        cout << a[ta%n] << b[ta%m] << "\n";
    }
}