#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

const ll mod=1e9+7;

ll n, m, i, j, v, r, p, k, ans, a[500001];
string s;
map<ll,ll> t;

bool pal(string g)
{
    bool tt=1;
    for (int i = 0; i < g.size()/2; i++) if (g[i]!=g[g.size()-1-i]) {tt=0;break;}
    return tt;
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        t[s[i]]++;
    }
    //cout << pal(s) << "\n";
    if (s.size()<=t[s[s.size()-1]]+1) {cout << "Impossible\n";exit(0);}
    string d1=s.substr(0,s.size()/2), d2=s.substr(s.size()/2+s.size()%2,s.size()/2);
    //cout << d1 << " " << d2 << "\n";
    ll ans=-1;
    if (s.size()%2==0 && d1!=d2) {cout << 1;exit(0);}
    bool tt=0;
    while (d1.size())
    {
        if (d1!=d2) {tt=1;break;}
        d1.erase(d1.size()-1,1);
        d2.erase(0,1);
    }
    if (tt) ans=2;
    string u=s, d="";
    ll n=s.size();
    for (int i = 0; i < n-1; i++)
    {
        d+=s[i];
        u.erase(0,1);
        //cout << u+d << "\n";
        if (pal(u+d) && u+d!=s) {cout << 1;exit(0);}
    }
    u=s, d="";
    for (int i = n-1; i > 0; i--)
    {
        d+=s[i];
        u.erase(u.size()-1,1);
        if (pal(d+u) && d+u!=s) {cout << 1;exit(0);}
    }
    if (ans==-1) {cout << "Impossible\n";exit(0);}
    cout << ans;
    return 0;
}