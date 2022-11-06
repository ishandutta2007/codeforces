#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t, n; 
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n;
    ll mx = 0;
    for(ll i = 1; i <= n; i++)
    {
        ll ta;
        cin >> ta;
        ll tb = mx + ta;
        mx = max(mx, tb);
        cout << tb << " ";
    }
    cout << "\n";
}