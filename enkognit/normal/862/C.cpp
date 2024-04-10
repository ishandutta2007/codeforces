#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimise("-O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

//#define {a...} make_struct(a...)
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>
#define pii pair<int,int>
#define y1 Enkognit
#define ld long double
#define sqr(a) ((a)*(a))

using namespace std;
using namespace __gnu_pbds;

template <typename ENKOGNIT>
using ordered_set = tree<ENKOGNIT, null_type, less<ENKOGNIT>, rb_tree_tag, tree_order_statistics_node_update>;

ll n, m, O, k, i, j, ans1, ans2, l, r, kl, OO=pow(2,18), o;
ll a[5000001];ll tt[200001];
vector<ll> c[100001];

int main()
{
    //freopen("bomb.in","r",stdin);
    //freopen("bomb.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    ll x=m, p=0;
    while (x)
    {
        p+=x%2;
        x/=2;
    }
    ll l=0;
    for (int i = 1; i <= 1e6; i++)
    {
        l^=i;
        a[i]=l;
    }
    if (n==1) {cout << "YES\n";cout << m << "\n";exit(0);}
    if (n==2) {if (m==0) cout << "NO\n"; else cout << "YES\n0 " << m << "\n";exit(0);}
    cout << "YES\n";
    for (int i = 1; i <= n-3; i++) cout << i << " ";
    if (a[n-3]==m) cout << OO << " " << OO/2 << " " << (OO^(OO/2)) << "\n"; else
    cout << "0 " << (a[n-3]^OO^m) << " " << OO << "\n";
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

*/