#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
#pragma GCC optimize("Ofast")
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

ll n, m, k, q, ans=1e18, l, r, i, j, x, y, kol=0, a[50][50], b[50][50];
string s, t;
vector <ll> v[1000], c[200001];


int main()
{
    //freopen("walk.in","r",stdin);
    //freopen("walk.out","w",stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    ll n, l, r;
    cin >> n >> l >> r;
    ll  p=(ll)pow(2,l), o=pow(2,r);
    cout << p-1+n-l << " " << o-1+(n-r)*o/2;
    return 0;
}


/*
2 4 4 2
1 2
1 4
2 3
2 1
1 3


*/