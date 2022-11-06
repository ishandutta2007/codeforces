#include<bits/stdc++.h>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
const ll NN = 1e4 + 5;
ll t;
ll b[99];
ll x[499][499];
vector<ll> v[99];
void dfs(ll pos)
{
    // cout << pos << "\n";
    b[pos] = 1;
    cout << char(pos + 'a');
    for(ll i = 0; i < v[pos].size(); i++)
        if(!b[v[pos][i]])
            dfs(v[pos][i]);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        if(s.length() == 1)
        {
            cout << "YES\n";
            for(ll i = 0;i < 26; i++)
                cout << char(i + 'a');
            cout << "\n";
            continue;
        }
        for(ll i = 0;i < 26; i++)
        {
            v[i].clear();
            b[i] = 0;
            for(ll j = 0;j < 26; j++)
                x[i + 'a'][j + 'a'] = 0;
        }
        // return 0;
        for(ll i = 1; i < s.length(); i++)
        {
            if(x[s[i - 1]][s[i]] == 0 && x[s[i]][s[i - 1]] == 0)
            {
                x[s[i - 1]][s[i]] = 1;
                x[s[i]][s[i - 1]] = 1;
                v[s[i - 1] - 'a'].pb(s[i] - 'a');
                v[s[i] - 'a'].pb(s[i - 1] - 'a');
            }
        }
        // return 0;
        ll bisa = 1;
        ll ada = 0;
        for(ll i = 0; i < 26; i++)
        {
            if(v[i].size() == 1)
                ada = 1;
            if(v[i].size() > 2)
            {
                bisa = 0;
            }
        }
        // return 0;
        if(!ada)
            bisa = 0;
        if(bisa)
        {
            // return 0;
            cout << "YES\n";
            for(ll i = 0; i < 26; i++)
                if(v[i].size() == 1)
                {
                    dfs(i);
                    break;
                }
            for(ll i = 0; i < 26; i++)
                if(!b[i])
                    cout << char(i + 'a');
            cout << "\n";
        }
        else
            cout << "NO\n";
    }
}