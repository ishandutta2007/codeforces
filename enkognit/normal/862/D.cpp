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
    //ios::sync_with_stdio(0);
    //cin.tie(0);
    cin >> n;
    string s="";
    for (int i = 0 ;i < n; i++) s+='0';
    ll p0=0, p1=0;
    cout << "? " <<s << "\n";
    cin >> p0;
    fflush(stdout);
    s[0]='1';
    cout << "? " <<s << "\n";
    cin >> p1;
    fflush(stdout);
    if (p0<p1)
    {
        ll l=0, r=n;
        while (l<r)
        {
            ll w=(l+r+1)/2;
            string d="";
            for (int i = 0; i < w; i++) d+='1';
            for (int i = 0; i < n-w; i++) d+='0';
            cout << "? " <<d << "\n";
            ll q;
            cin >> q;
            fflush(stdout);
            if (q-p0==w) l=w; else r=w-1;
        }
        cout << "! 1 " << l+1 << "\n";
    } else
    {
        ll l=0, r=n;
        string d="";
        for (int i = 0; i < n; i++) d+='1';
        cout << "? " <<d << "\n";
        ll p;
        cin >> p;
        fflush(stdout);
        while (l<r)
        {
            int w=(l+r+1)/2;
            string d="";
            for (int i = 0; i < w; i++) d+='0';
            for (int i = 0; i < n-w; i++) d+='1';
            cout << "? " << d << "\n";
            ll q;
            cin >> q;
            fflush(stdout);
            if (q-p==w) l=w; else r=w-1;
        }
        cout << "! " << l+1 << " 1\n";
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

*/