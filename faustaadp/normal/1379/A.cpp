#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll t, n;
string z;
char a[55];
string x = "abacaba", s;
string hai(ll L, ll R)
{
    string H = "";
    for(ll i = L; i <= R; i++)
        H += z[i];
    return H;
}
ll cek(ll L, ll R)
{
    z = s;
    z = "0" + z;
    for(ll i = L; i <= R; i++)
        if(z[i] == '?')
            z[i] = x[i - L];
        else
        if(z[i] != x[i - L])
            return 0; 
    // cout << z << "_\n";
    for(ll i = 1; i <= n; i++)
        if(z[i] == '?')
            z[i] = 'z';
    ll H = 0;
    for(ll i = 1; (i + 6) <= n; i++)
    {
        // cout << i << "   " << hai(i, i + 6) << "\n";
        if(hai(i, i + 6) == x)
            H++;
    }
    // cout << H << "\n";
    z = z.substr(1, n);
    return (H == 1);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> t;
    while(t--)
    {
        cin >> n;
        s = "";
        for(ll i = 1; i <= n; i++)
        {
            cin >> a[i];
            s += a[i];
        }
        ll ada = 0;
        for(ll i = 1; (i + 6) <= n; i++)
            if(cek(i, i + 6))
            {
                ada = 1;
                cout << "Yes\n";
                cout << z << "\n";
                break;
            }
        if(!ada)
            cout << "No\n";
    }
}