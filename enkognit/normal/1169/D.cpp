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

ll n, m, i, j, ans;
string s;

bool check(ll l,ll r)
{
    for (int i = l; i <= r; i++)
        for (int j = 1; j <= (r-i)/2; j++)
            if (s[i]==s[i+j] && s[i]==s[i+j*2]) return 1;
    return 0;
}

int main()
{
    //ios_base::sync_with_stdio(0);
    cin >> s;
    s=' '+s;
    ll n=s.size()-1;
    for (int i = 1; i <= n-2; i++)
        for (int j = i+2; j <= n; j++)
            if (check(i,j)) {ans+=n-j+1;break;}
    cout << ans;
    return 0;
}
/*
10000 10000 2
1 4232
3 1 10000 4231 10000
*/