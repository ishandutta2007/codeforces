#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 5e5 + 5;
const ll mo = 1e9 + 7;
ll b[9999], TC;
string solve(string s1, string s2)
{
    TC++;
    ll L1 = s1.length();
    ll L2 = s2.length();
    if(L1 < L2)
        return "NO";
    ll now = L1 - 1;
    for(ll i = L2 - 1; i >= 0; i--)
    {
        if(b[s2[i]] == TC)
            return "NO";
        while(now >= 0 && s1[now] != s2[i])
        {
            // cout << now << " " << i << "\n";
            b[s1[now]] = TC;
            now--;
        }
        // cout << now << " " << i << "\n";
        if(now < 0)
            return "NO";
        now--;
    }
    return "YES";
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    ll T;
    cin >> T;
    while(T--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        cout << solve(s1, s2) << "\n";
    }
}