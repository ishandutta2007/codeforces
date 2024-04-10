#include <bits/stdc++.h>
#define ll long long
#define fr front()
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define pu push
#define pll pair<ll,ll>


using namespace std;

ll n, m, k, i, j, l, r, a[200001];

int main()
{
    cin >> m >> n;
    ll e=0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (i+1==n) e+=a[i]%2; else e+=(m%2)*(a[i]%2);
    }
    //cout << e;
    if (e%2) cout << "odd"; else cout << "even";
    return 0;
}