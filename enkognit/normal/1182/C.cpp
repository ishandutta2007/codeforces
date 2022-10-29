#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

int n, m, i, j, x, k, ans, kol[3000001];
string s[100001];
bool t[100001], tt[100001];
vector <pair<pair<ll,char> ,ll> > v, z;

int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie();cout.tie();
    //ll x, y, z;
    cin >> n;
    string f="aeoui";
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        ll x=0;
        char c=0;
        for (int j = 0; j < s[i].size(); j++)
            if (f.find(s[i][j])!=string::npos)
            {
                c=s[i][j];
                x++;
            }
        v.pb(mp(mp(x,c),i));
    }
    //cout << v.size() << "\n";
    sort(v.begin(),v.end());
    vector <pll> z1, z2;
    for (int i = 1; i < v.size(); i++)
        if (v[i].fi==v[i-1].fi && t[i-1]==0)
        {
            z1.pb(mp(v[i].se, v[i-1].se));
            t[i-1]=1;
            t[i]=1;
        }

    for (int i = 0; i < v.size(); i++)if (!t[i]) z.pb(v[i]);

    for (int i = 1; i < z.size(); i++)
        if (z[i].fi.fi==z[i-1].fi.fi && !tt[i-1])
        {
            z2.pb(mp(z[i].se, z[i-1].se));
            tt[i]=1;
            tt[i-1]=1;
        }
    //cout << z2.size() << " " << z1.size() << "\n";

    cout << min(z2.size(),z1.size())+(z1.size()-min(z2.size(),z1.size()))/2 << "\n";
    if (min(z2.size(),z1.size())+(z1.size()-min(z2.size(),z1.size()))/2==0) exit(0);
    for (int i = 0; i < min(z2.size(),z1.size()); i++)
    {
        cout << s[z2[i].fi] << " " << s[z1[i].fi] << "\n";
        cout << s[z2[i].se] << " " << s[z1[i].se] << "\n";
    }
    //cout << "\n";
    for (int i = min(z2.size(),z1.size()); i < z1.size()-1; i+=2)
    {
        cout << s[z1[i].fi] << " " << s[z1[i+1].fi] << "\n";
        cout << s[z1[i].se] << " " << s[z1[i+1].se] << "\n";
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/