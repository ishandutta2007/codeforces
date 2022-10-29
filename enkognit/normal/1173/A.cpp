#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define fi first
#define mp make_pair
#define se second
#define pb push_back
#define pll pair<ll,ll>
#define pii pair<int,int>

using namespace std;

ll n, m, i, j, x, k, ans, b[1001][1001];
ll a[500050];
string s, d;
vector <pll> v;
//bool t[10000001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    ll x, y, z;
    cin >> x >> y >> z;
    if (z==0 && x==y) cout << 0; else
    if (x-y-z>0) cout << "+"; else
    if (y-x-z>0) cout << "-"; else cout << "?";
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/