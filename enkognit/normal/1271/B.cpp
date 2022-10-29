#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define fi first
#define se second
#define pld pair<ld,ld>
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

ll md1=1e9+7, md2=998244357, p1=31, p2=127;

ll n, m, k, a, b, c, e, f, l, r, i, j;
bool tt[1000001];
string s, d;

void inv(char &c)
{
    if (c=='B') c='W'; else c='B';
}

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    cin >> s;
    vector <ll> v1, v2;
    bool t1=0, t2=0;
    d=s;
    for (int i = 0; i < n-1; i++)
    {
        if (s[i]!='W') inv(s[i]), inv(s[i+1]), v1.pb(i+1);
    }
    for (int i = 0; i < n-1; i++)
    {
        if (d[i]!='B') inv(d[i]), inv(d[i+1]), v2.pb(i+1);
    }
    if (s[s.size()-1]=='B') t1=1;
    if (d[d.size()-1]=='W') t2=1;
    if (t1 && t2) cout << -1; else
    if (t1)
    {
        cout << v2.size() << "\n";
        for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
        cout << "\n";
    }else
    if (t2)
    {
        cout << v1.size() << "\n";
        for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
        cout << "\n";
    }else
    if (v1.size()>v2.size())
    {
        cout << v2.size() << "\n";
        for (int i = 0; i < v2.size(); i++) cout << v2[i] << " ";
        cout << "\n";
    }else
    {
        cout << v1.size() << "\n";
        for (int i = 0; i < v1.size(); i++) cout << v1[i] << " ";
        cout << "\n";
    }
    return 0;
}
/*
6 5 2
5 1 3 6 2 4
1 3
1 6
3 5
4 5
2 2

3 3 5
1 12 6
1 3
2 3
1 2

7 6 1
1 8 9 3 12 5 2
3 5
4 6
1 3
2 2
2 6
3 5
*/