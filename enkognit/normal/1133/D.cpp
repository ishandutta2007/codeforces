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

ll n, m, l, r, k, h, i, j, T, ans;
ll a[500001], b[500001];
vector <ll> v;
map <ld,int> t;
string s,d;

int main()
{
    //freopen("sum.in","r",stdin);
    //freopen("sum.out","w",stdout);
    ios_base::sync_with_stdio(0);cin.tie(0);
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]==b[i] && a[i]==0) k++; else
        if (a[i]!=0)
        t[(ld)(-b[i])/(ld)a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i]!=0)
        ans=max((ll)t[(ld)(-b[i])/(ld)a[i]],ans);
    }
    cout << ans+k;
    return 0;
}