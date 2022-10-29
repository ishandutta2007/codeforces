#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define pll pair<ll,ll>
#define fi first
#define se second

using namespace std;

ll n, m, i, j, k, l, r, a[1000001];
string s, d;
vector <ll> v, c[300001];
bool t[1000001];

string sum(string x, string y)
{
    reverse(x.begin(),x.end());
    reverse(y.begin(),y.end());
    while (x.size()<y.size()) x=x+'0';
    while (x.size()>y.size()) y=y+'0';
    ll p=0;
    string ans="";
    for (int i = 0; i < x.size(); i++)
    {
        ll o=(x[i]+y[i]-'0'-'0'+p);
        p=0;
        if (o>9) p=1;
        ans+=o%10+'0';

    }
    if (p) ans+=p+'0';
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
    cin >> n;
    cin >> s;
    s=' '+s;
    ll l=n/2+(n%2), r=l+1;
    while (s[l]=='0') l--;
    while (s[r]=='0') r++;
    if (l==1)
    {
        string x="", y="";
        for (int i = 1; i < r; i++) x+=s[i];
        for (int i = r; i <= n; i++) y+=s[i];
        cout << sum(x,y) << "\n";
        exit(0);
    }
    if (r==n+1)
    {
        string x="", y="";
        for (int i = 1; i < l; i++) x+=s[i];
        for (int i = l; i <= n; i++) y+=s[i];
        cout << sum(x,y) << "\n";
        exit(0);
    }
    string x="", y="";
        for (int i = 1; i < l; i++) x+=s[i];
        for (int i = l; i <= n; i++) y+=s[i];
    string p1=sum(x,y);
    x="", y="";
        for (int i = 1; i < r; i++) x+=s[i];
        for (int i = r; i <= n; i++) y+=s[i];
      string p2=sum(x,y);
    if (p1.size()<p2.size() || (p1.size()==p2.size() && p1<=p2)) cout << p1; else cout << p2;
}