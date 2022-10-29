#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define pll pair<ll,ll>
#define se second
#define fi first
#define ld long double

using namespace std;

ll md1=1e9+9, md2=998244357, p1=31, p2=127;

ll n, m, k, i, j, a[1000001], x;
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    a[0]=6;
    a[1]=2;
    a[2]=5;
    a[3]=5;
    a[4]=4;
    a[5]=5;
    a[6]=6;
    a[7]=3;
    a[8]=7;
    a[9]=6;
    cin >> t;
    while (t--)
    {
        cin >> n;
        string s="";
        while (n>=2)
        {
            n-=2;
            s+='1';
        }
        if (n==1) s.back()='7';
        reverse(s.begin(),s.end());
        cout << s << "\n";
    }
    return 0;
}