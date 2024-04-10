#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 3e5 + 5;
ll n, has;
map<string, ll> me;
string s;
ll x[9999];
ll S[33][101010];
ll p[33][101010];
ll xx[999][999];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s;
    n = s.length();
    for(ll i = 0;i < n; i++)
    {
        x[s[i]]++;
        has = max(has, x[s[i]]);
        has = max(has, x[s[i]] * (x[s[i]] - 1) / 2);
    }
    for(ll i = 0;i < n; i++)
        for(ll j = 'a'; j <= 'z'; j++)
        {
            if(i > 0)
                p[j - 'a'][i] = p[j - 'a'][i - 1];
            if(s[i] == j)
                p[j - 'a'][i]++;
        }
    for(ll i = (n - 1);i >= 0; i--)
        for(ll j = 'a'; j <= 'z'; j++)
        {
            S[j - 'a'][i] = S[j - 'a'][i + 1];
            if(s[i] == j)
                S[j - 'a'][i]++;
        }
    for(ll j = 0; j < 26; j++)
            for(ll k = 0; k < 26; k++)
            {
                if(j == k)
                    continue;
                ll hz = 0;
                for(ll i = 0 ;i < n; i++)
                {
                    if(s[i] == j + 'a')
                        xx[j][k]++;
                    if(s[i] == k + 'a')
                    {
                        // if(j == 0 && k == 1)
                            // cout << xx[j][k] << "\n";
                        hz += xx[j][k];
                    }
                }
                has = max(has, hz);
            }
    cout << has << "\n";

}