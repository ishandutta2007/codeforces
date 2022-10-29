#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define fi first
#define fr front()
#define se second
#define pll pair<ll,ll>

using namespace std;

const ll MOD=1000000007;

ll n, m, i, j, Q, k, l, dp[300001], a[300001], pref[300001];string s;
vector <ll> v, ans;

bool lo(ll h)
{
    while (h%2==0) h/=2;
    return (h==1);
}

ll gcd(ll x,ll y)
{
    if (x==0) return y; else
    if (y==0) return x; else
    return __gcd(x,y);
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll h=abs(n-m), p=sqrt(h), ans=n*m/gcd(n,m), q=0;
    for (int i = 1; i <= p; i++)
        if (h%i==0)
        {
            ll a=n-n%i+i, b=m-m%i+i, w=a*b/gcd(a,b);
            if (ans>w) ans=w, q=i-n%i;
            //cout << w << " " << i << "\n";
            ll j=h/i;
            a=n-n%j+j, b=m-m%j+j, w=a*b/gcd(a,b);
            if (ans>w) ans=w, q=j-n%j;
            //cout << w << " " << j << "\n";
        }
    cout << q;
}
/*
10 11
1 2
1 3
1 4
3 4
2 5
2 6
5 6
3 7
4 8
5 9
6 10
*/