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
    //ll x, y, z;
    cin >> n;
    ll l=1, r=1000;
    while (l<r)
    {
        ll w=(l+r)/2;
        if (w+w-1<n) l=w+1; else r=w;
    }
    cout << l << "\n";
    for (int i = 1; i <= l; i++) cout << "1 " << i << "\n";
    for (int i = 1; i <= n-l; i++) cout << l << " " << i+1 << "\n";
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/