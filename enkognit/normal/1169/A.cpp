#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>

using namespace std;

//ll n, m, i, j, k, l, r, ans, T, Q, K, a[300001], b[100001];
//string s, d;
//vector <ll> c[300001], v;

bool t[1000001], p[10001];

int main()
{
    //ios_base::sync_with_stdio(0);
    ll a, b, x, y, n;
    cin >> n >> a >> x >> b >> y;
    ll z=0;
    while (a!=x && b!=y)
    {
        a++;
        b--;
        if (a==n+1) a=1;
        if (b==0) b=n;
        if (a==b) {cout << "YES\n";exit(0);}
    }
    cout << "NO\n";
    return 0;
}
/*
10000 10000 2
1 4232
3 1 10000 4231 10000
*/