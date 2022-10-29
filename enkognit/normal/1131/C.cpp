#include <bits/stdc++.h>

#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define pll pair<ll,ll>
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;

ll n, m, i, k, ans, l, r, no, yes, a[1000001], b[1000001];
map<ll,bool> tt={};
string s, d;

int main()
{
    //freopen("roulette.in","r",stdin);
    //freopen("roulette.out","w",stdout);
    ios_base::sync_with_stdio(0);
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a,a+n);
    for (int i = 0; i < n; i+=2)
    {
        if (i==n-1) b[n/2+1]=a[i]; else
        {
            b[i/2+1]=a[i];
            b[n-i/2]=a[i+1];
        }
    }
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    return 0;
}