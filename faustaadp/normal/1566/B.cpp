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
        ll cnt[2];
        string s;
        cin >> s;
        ll n = s.length();
        cnt[0] = 0;
        cnt[1] = 0;
        ll has = 2;
        for(ll i = 0; i < n; i++)
            cnt[s[i] - '0']++;
        if(cnt[1] == n)
            has = 0;
        else
        if(cnt[0] == n)
            has = 1;
        else
        {
            ll CC = 0;
            for(ll i = 0; i < n; i++)
                if(s[i] == '0')
                {
                    if(i == 0 || s[i - 1] == '1')
                        CC++;
                }
            has = min(has, CC);
        }
        cout << has << "\n";
    }
}