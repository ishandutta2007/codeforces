#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#define mp make_pair
#define ll long long
#define fi first
#define se second
#define fr front()
#define pb push_back
#define sqr(a) ((a)*(a))
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

ll n, m, it, i, p, k, T, j, tt[1000001], in[100001], out[100001], B, C, y, kol, d[1000001];
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll g;
    cin >> g;
    while (g--)
    {
        string s, t;
        cin >> s;
        cin >> t;
        for (int i = 0; i < 100; i++) tt[i]=0;
        for (int i = 0; i < s.size(); i++)
        {
            tt[s[i]-'a']=1;
        }
        for (int i = 0; i < t.size(); i++)
        {
            if (tt[t[i]-'a'])tt[t[i]-'a']=2;
        }
        ll p=0;
        for (int i =0 ;i < 50; i++) if (tt[i]==2) p=1;
        if (p) cout << "YES\n"; else cout << "NO\n";
    }
}
/*
9 12
1 9 4
1 2 5
2 3 7
2 4 3
4 3 6
3 6 4
8 7 10
6 7 5
5 8 1
9 5 7
5 4 12
6 8 2
2
4 7
5
1 6
5 3
4 8
5 8
1 5
*/