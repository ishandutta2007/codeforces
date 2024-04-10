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
ll t, n, m;
string s1, s2;
ll cek(ll pos, ll A, ll B)
{
    if(s1[pos] != s2[0])
        return 0;
    // cout << pos << " " << A << " " << B << "\n";
    ll idx = 0;
    for(ll i = 0; i < A; i++)
    {
        idx++;
        pos++;
        // cout << pos << " " << idx << "\n";
        if(idx >= n)
            return 0;
        if(s1[pos] != s2[idx])return 0;
    }
    for(ll i = 0; i < B; i++)
    {
        idx++;
        pos--;
        if(idx < 0)
            return 0;
        if(s1[pos] != s2[idx])return 0;
    }
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> s1 >> s2;
        n = s1.length();
        m = s2.length();
        bool ya = 0;
        for(ll i = 0; i < n; i++)
            for(ll j = 0; j < m ; j++)
                if(cek(i, j, m - j - 1))
                    ya = 1;
        if(ya)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}