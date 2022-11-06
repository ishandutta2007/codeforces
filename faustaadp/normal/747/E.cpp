#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 1e6 + 5;
string s;
ll n, a[NN];
vector<string> jaw[NN];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    cin >> s;
    string z = "";
    ll sz = s.length();
    vector<string> isi;
    for(ll i = 0; i <= sz; i++)
    {
        if(i == sz || s[i] == ',')
        {
            isi.pb(z);
            z = "";
        }
        else
            z += s[i];
    }
    ll te = 0, ma = 0;
    n = isi.size();
    for(ll i = 0; i < n; i++)
    {
        // cout << isi[i] << " " << te << "@\n";
        if('0' <= isi[i][0] && isi[i][0] <= '9')
        {
            ll ang = stoll(isi[i]);
            te++;
            // cout << ang << " " << te << "__\n";
            a[te] += ang;
        }
        else
        {
         while((te > 0) && (a[te] == 0))
            te--;
            ma = max(ma, te);
            jaw[te].pb(isi[i]);
            a[te]--;
            // cout << te << " " << isi[i] << "\n";
        }
    }
    cout << ma + 1 << "\n";
    for(ll i = 0; i <= ma; i++)
    {
        for(ll j = 0; j < jaw[i].size(); j++)
            cout << jaw[i][j] << " ";
        cout << "\n";
    }
}