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
#define y1 Enkognit

using namespace std;

const ll MOD=1e9+7;

ll n, m, i, p, k, T, j, A, B, C, y, kol, a[1000001];
ll b[80];
string s, t;
bool tt[101];
vector <ll> v, c[300005];


int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll l, r;
    cin >> l >> r;
    for (int i = l; i <= r; i++)
    {
        ll m=i;
        bool t=0;
        for (int j = 0; j < 10; j++) tt[j]=0;
        while (m)
        {
            if (tt[m%10]) {t=1;break;}
            tt[m%10]=1;
            m/=10;
        }
        if (!t) {cout << i;exit(0);}
    }
    cout <<  -1;
}