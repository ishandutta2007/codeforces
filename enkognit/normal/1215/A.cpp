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

ll n, m, i, p, k, T, j, y, kol, a[1000001];
vector <ll> v, c[300001];
string s, d;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll a1, a2, k1, k2;
    cin >> a1 >> a2 >> k1 >> k2;
    if (k1>k2) swap(k1,k2), swap(a1,a2);
    cin >> n;
    cout << max(0ll, n-a1*(k1-1)-a2*(k2-1)) << " ";
    ll p=n, e=0;
    for (int i = 0; i < a1; i++)
    {
        if (p<k1) {cout << e;exit(0);}
        p-=k1;
        e++;
        if (p==0) {cout << e;exit(0);}
    }
    for (int i = 0; i < a2; i++)
    {
        if (p<k2) {cout << e;exit(0);}
        p-=k2;
        e++;
        if (p==0) {cout << e;exit(0);}
    }
    cout << e;
    return 0;
}