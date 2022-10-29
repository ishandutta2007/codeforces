#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("unroll-loops")
//#pragma GCC optimize("popcnt")
#include <random>
#include <time.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define pll pair<ll,ll>
#define pii pair<int,int>
#define ld long double

using namespace std;

mt19937_64 rnd(time(0));

ll n, m, k;

void solve()
{
    string s;
    cin >> n;
    cin >> s;
    s=' '+s;

    ll z=0, k=0;

    for (int i = 1; i <= n/2; i++)
    {
        if (s[i]!=s[n-i+1] || (i==n-i+1 && s[i]=='0')) z++; else
        if (s[i]==s[n-i+1] && s[i]=='0') k++;
    }

    ll o=0;

    if (n%2 && s[(n+1)/2]=='0') o=1;

    //cout << k << " " << z << "\n";

    ll o1=0, o2=0, j=0;

    if (o==0)
    {
        cout << "BOB\n";
    }else
    if (o==1)
    {
        if (k==0) cout << "BOB\n"; else cout << "ALICE\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
/*
1000000000000000 4523 3
456 23
4562 78
456239 456
*/