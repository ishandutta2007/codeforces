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

ll n, m, i, j, x, a[300005], ans;
string s, d;
vector <ll> c[300005], v, p;

int main()
{
    //ios_base::sync_with_stdio(0);
    cin.tie();cout.tie();
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        for (int i = 0; i < n; i++) cin >> a[i];
        ll p=0, mn=1e18;
        for (int i = k; i < n; i++)
        {
            if (a[i]-a[i-k]<mn) mn=a[i]-a[i-k], p=i;
        }
        cout << (a[p]+a[p-k])/2 << "\n";
    }
    return 0;
}
/*
10 2
abacdabcda
7 10 0
5 8 1

*/