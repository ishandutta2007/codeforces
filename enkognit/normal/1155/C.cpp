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

ll n, m, i, j, Q, k, l, T, a[300001];
string s;
vector <ll> v;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cin >> n >> m;
    ll p;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i==1) p=a[i]-a[i-1]; else
        if (i>1) p=__gcd(p,a[i]-a[i-1]);
    }
    for (int i = 0; i < m; i++)
    {
        ll x;
        cin >> x;
        if (p%x==0) {cout <<"YES\n"<< a[0] << " " << i+1 << "\n";;exit(0);}
    }
    cout << "NO\n";
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