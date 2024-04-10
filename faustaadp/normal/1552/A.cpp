#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll t;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        string s, z;
        cin >> s;
        z = s;
        sort(z.begin(), z.end());
        ll has = 0;
        for(ll i = 0; i < n; i++)
            has += z[i] != s[i];
        cout << has << "\n";   
    }
}