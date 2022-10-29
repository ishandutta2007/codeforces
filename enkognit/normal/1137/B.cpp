#include <bits/stdc++.h>

#define ll long long
#define fi first
#define fr front()
#define se second
#define pb push_back
#define mp make_pair
#define sqr(a) ((a)*(a))
#define ld long double
#define pll pair<ll,ll>
#define pii pair<int,int>
//#define pi 3.14159265358979323846

using namespace std;

ll n, m, k, j, o, ans, p[500005], k1, k0;
string s, d;
vector <ll> z;

int main()
{
	//freopen("race.in", "r", stdin);
	//freopen("race.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
	cin >> s;
	cin >> d;
	for (int i = 1; i < d.size(); i++)
    {
        ll j=p[i-1];
        while (j>0 && d[i]!=d[j]) j=p[j-1];
        if (d[i]==d[j]) j++;
        p[i]=j;
    }
    for (int i = 0; i < s.size(); i++) if (s[i]=='1') k1++; else k0++;
    ll k=p[d.size()-1];
    string u=d.substr(k,d.size()-k);
    ll u1=0, u0=0, d1=0, d0=0;
    for (int i = 0; i < u.size(); i++) if (u[i]=='1') u1++; else u0++;
    for (int i = 0; i < d.size(); i++) if (d[i]=='1') d1++; else d0++;
    string ans="";
    if (k1>=d1 && k0>=d0)
    {
        k1-=d1;
        k0-=d0;
        ans+=d;
        while (k1>=u1 && k0>=u0)
        {
            ans+=u;
            k1-=u1;
            k0-=u0;
        }
    }
    for (int i = 0; i < k1; i++) ans+='1';
    for (int i = 0; i < k0; i++) ans+='0';
    cout << ans;
    return 0;
}