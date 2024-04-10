#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
const ll NN = 2e5 + 5;
const ll mo = 1e9 + 7;
ll n;
vector<ll> cal;
void coba()
{
    vector<ll> ve[4];
    for(ll i = 0; i < cal.size(); i++)
        ve[i % 4].pb(cal[i]);
    string j1, j2;
    cout << "? " << (ve[0].size() + ve[1].size());
    for(auto isi : ve[0])cout << " " << isi;
    for(auto isi : ve[1])cout << " " << isi;
    cout << endl;
    cin >> j1;

    cout << "? " << (ve[0].size() + ve[2].size());
    for(auto isi : ve[0])cout << " " << isi;
    for(auto isi : ve[2])cout << " " << isi;
    cout << endl;
    cin >> j2;
    cal.clear();
    if(j1 == "YES" && j2 == "YES")
    {
        for(auto isi : ve[0])cal.pb(isi);
        for(auto isi : ve[1])cal.pb(isi);
        for(auto isi : ve[2])cal.pb(isi);
    }
    else
    if(j1 == "YES" && j2 == "NO")
    {
        for(auto isi : ve[0])cal.pb(isi);
        for(auto isi : ve[1])cal.pb(isi);
        for(auto isi : ve[3])cal.pb(isi);
    }
    else
    if(j1 == "NO" && j2 == "YES")
    {
        for(auto isi : ve[0])cal.pb(isi);
        for(auto isi : ve[2])cal.pb(isi);
        for(auto isi : ve[3])cal.pb(isi);
    }
    else
    {
        for(auto isi : ve[1])cal.pb(isi);
        for(auto isi : ve[2])cal.pb(isi);
        for(auto isi : ve[3])cal.pb(isi);
    }
}
int main()
{
    cin >> n;
    for(ll i = 1; i <= n; i++)
        cal.pb(i);
    while(cal.size() > 3)
        coba();
    if(cal.size() <= 2)
    {
        cout << "! " << cal[0] << endl;
        string z;
        cin >> z;
        if(z == ":)")
            return 0;
        cout << "! " << cal[1] << endl;
        cin >> z;
    }
    else
    {
        cout << "? 1 " << cal[0] << endl;
        string res;
        cin >> res;
        ll x;
        if(res == "YES")
            x = 0;
        else
        {
            cout << "? 1 " << cal[0] << endl;
            string res;
            cin >> res;
            if(res == "YES")
                x = 0;
            else
            {
                cout << "? 1 " << cal[1] << endl;
                string res;
                cin >> res;
                if(res == "YES")
                    x = 1;
                else
                {
                    cout << "? 1 " << cal[1] << endl;
                    string res;
                    cin >> res;
                    if(res == "YES")
                        x = 1;
                    else
                        x = 2;
                }
            }
        }
        cout << "! " << cal[x] << endl;
        string z;
        cin >> z;
        if(z == ":)")
            return 0;
        ll y = 0;
        if(x == 0)
            y = 1;

        cout << "? 1 " << cal[y] << endl;
        cin >> res;
        if(res == "YES")
        {
            cout << "! " << cal[y] << endl;
        }
        else
        {
            cout << "! " << cal[3 - x - y] << endl;
        }



        
    }
}