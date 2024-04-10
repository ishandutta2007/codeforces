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

ll n, m, i, j, k, r, p;
string s;
map<char,ll> t;
map<ll,ll> g;

void ex(ll l,ll r)
{
    char c='A';
    for (int i = 0; i < s.size(); i++)
        if (i<l || i>r)
        {
            if (s[i]=='?') s[i]='A';
        }else
    {
        //cout << y[i] << ":\n ";
        if (s[i]=='?')
        {
            while (t[c]>0) {c++;}
            s[i]=c;
            t[c]=1;
        }
        //cout << "\n";
    }
    cout << s;
    exit(0);
}

int main()
{
    //freopen("invite.in","r",stdin);
    //freopen("invite.out","w",stdout);
    cin >> s;
    if (s.size()<26) {cout << -1;exit(0);}
    ll k=0;
    g[0]=26;
    for (int i = 0; i < 26; i++)
    {
        if (s[i]=='?') {k++;continue;}
        g[t[s[i]]]--;
        t[s[i]]++;
        g[t[s[i]]]++;
    }
    //cout << k << " " << g[1] << "\n";
    if (k+g[1]==26) ex(0,25);

    for (int i = 26; i < s.size(); i++)
    {
        if (s[i-26]=='?') k--; else
        {
            g[t[s[i-26]]]--;
            t[s[i-26]]--;
            g[t[s[i-26]]]++;
        }
        if (s[i]=='?') k++; else
        {
            g[t[s[i]]]--;
            t[s[i]]++;
            g[t[s[i]]]++;
        }
        if (g[1]+k==26) ex(i-25,i);
    }
    cout << -1;
    return 0;
}