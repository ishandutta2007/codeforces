#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
//#pragma GCC optimize("-Otime")
//#pragma GCC optimize("unr")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define y1 Enkognit

using namespace std;

int n, m, i, j, k, l, r, a[2001][2001];
int d[2001][10001];
string t, s;

int main()
{
    //freopen("tickets.in","r",stdin);
    //freopen("tickets.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> s;
    cin >> t;
    ll n=s.size();
    vector <ll> z={}, v={};
    ll ans=0, p=0, o=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]==t[p]) {p++;o=0;v.pb(i);} else {o++;ans=max(ans,o);}
        if (p==t.size())
        {
            ans=max(ans,n-1-i);
        }
    }
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    p=0, o=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]==t[p]) {p++;o=0;z.pb(n-1-i);} else {o++;ans=max(ans,o);}
        if (p==t.size())
        {
            ans=max(ans,n-1-i);
        }
    }
    reverse(z.begin(),z.end());
    for (int i = 0; i < v.size()-1; i++)
    {
        ans=max(ans,z[i+1]-v[i]-1);
    }
    cout << ans;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/