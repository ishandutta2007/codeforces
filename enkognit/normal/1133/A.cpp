#include <bits/stdc++.h>
#include <cstdlib>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define len length()
#define pll pair<ll,ll>
#define el endl
#define pu push
#define sqr(a) ((a)*(a))
#define pld pair<long double,long double>
#define ld long double

using namespace std;

ld PI=3.14159265359, sec_clock=1e8;

ll n, m, l, r, k, h, i, j, T;
ll a[500001];
ll v[5002];
map <ll,ll> t;
string s,d;

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> s;
    cin >> d;
    n=atoi(s.substr(0,2).c_str());
    l=atoi(s.substr(3,2).c_str());
    m=atoi(d.substr(0,2).c_str());
    r=atoi(d.substr(3,2).c_str());
    l+=n*60;
    r+=m*60;
    r=(r+l)/2;
    ll o=0;
    while (r>=60) r-=60, o++;
    if (o<10)cout << 0;
    cout << o << ":";
    if (r<10) cout << 0;
    cout << r;
    return 0;
}