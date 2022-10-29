#include <bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define fr front()
#define sqr(a) ((a)*(a))
#define y1 Enkognit

using namespace std;

const ll MOD=1000000007;

ll n, m, W, l, r, ans, k, x[100001], y[100001];
string s, d, t;
vector <pair<pll,ll> > v;

ll gcd(ll a,ll b)
{
    a=abs(a),b=abs(b);
    if (a==0 || b==0) return a+b; else  return __gcd(a,b);
}

int main()
{
    //freopen("divisors.in","r",stdin);
    //freopen("divisors.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    ll k=0;
    for (int i = 0; i < n; i++)
    {
        if (s[i]=='-') k=max(0ll,k-1); else k++;
    }
    cout << k;
    return 0;
}
/*
5
2 3 4 5 6
6
1 2 4
1 2 3
0 1 1
0 4 7
1 1 3
1 1 4

*/