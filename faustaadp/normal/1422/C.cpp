#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
ll sat[NN], has, n, mo = 1e9 + 7;
ll sep[NN];
string s;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    sep[1] = 1;
    for(ll i = 2; i <= 100000; i++) 
        sep[i] = (sep[i - 1] * 10) % mo;
    for(ll i = 1; i <= 100000; i++) 
        sat[i] = (sat[i - 1] + sep[i] * i) % mo;
    cin >> s;
    n = s.length();
    for(ll i = 0; i < n; i++)
    {
        ll z = (i * (i + 1)) / 2;
        z %= mo;
        // cout << sat[n - i - 1] << " " << (s[i] - '0') << "\n";
        // cout << sep[n - i] << " " << (s[i] - '0') << "\n";
        has = (has + sat[n - i - 1] * (ll)(s[i] - '0')) % mo;
        has = (has + sep[n - i] * (ll)(s[i] - '0') * z) % mo;
    }
    // cout << angka << "\n";
    // has = (has + mo - angka) % mo;
    cout << has << "\n";
}