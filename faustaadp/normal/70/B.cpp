#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
ll n;
string s;
vector<ll> isi;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0); 
    cin >> n;
    getline(cin, s);
    getline(cin, s);
    ll bsr = 0, byk = 0;
    for(ll i = 0; i < s.length(); i++)
    {
        bsr++;
        if(bsr > n)
        {
            cout << "Impossible\n";
            return 0;
        }
        if(s[i] == '.' || s[i] == '?' || s[i] == '!')
        {
            isi.pb(bsr);
            i++;
            bsr = 0;
        }
    }
    ll hz = 0;
    for(ll i = 0; i < isi.size(); i++)
    {
        // cout << isi[i] << " " << hz + isi[i] + 1 << "\n";
        if(i == 0 || (hz + isi[i] + 1 > n))
        {
            // cout << i << "_\n";
            byk++;
            hz = isi[i];
        }
        else
            hz += isi[i] + 1;
    }
    cout << byk << "\n";
}