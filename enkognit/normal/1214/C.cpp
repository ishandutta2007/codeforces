#include <bits/stdc++.h>
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
#define y1 Enkognit

using namespace std;

const ll MOD = 998244353;

ll n, k, q, l, m, r, i, j, x, y, ans;
vector <ll> e, v;
string s;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n;
    cin >> s;
    ll l=0, r=0, p=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]==')') p--,r++; else p++,l++;
        if (p<-1) {cout << "No\n";exit(0);}
    }
    if (l!=r) cout << "No\n"; else cout << "Yes\n";
    return 0;
}
/*
6 15
E 5
V 9
M 3
V 2
M 5
V 6
*/