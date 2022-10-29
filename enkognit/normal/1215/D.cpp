#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

ll n, m, i, p, k, T, j, y, kol, tt[1000001];
string s, t;
vector <pair<pair<char,char>,ll> > u, z;
ll c[1001];

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    ll l=0, r=0, sm=0;
    for (int i = 0; i < s.size()/2; i++)
        if (s[i]=='?') l++; else sm+=s[i]-48;
    for (int i = s.size()/2; i < s.size(); i++)
        if (s[i]=='?') r++; else sm-=s[i]-48;
    if (sm<0)
        sm*=-1, swap(l,r);
    ll t2=r%2+r/2, t1=l%2+l/2;
    //cout << sm+t1*9 << " " << 9*(r-(l+r)/2+t1) << " " << t2*9-sm << " " << 9*(l-(l+r)/2+t2) << "\n";
    if (sm+t1*9<=9*(r-(l+r)/2+t1) && t2*9-sm<=9*(l-(l+r)/2+t2)) cout << "Bicarp"; else cout << "Monocarp";
    return 0;
}