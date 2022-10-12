#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

ll d[500005];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    d[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 2*i; j <= n; j += i)
            d[j-1] = i;
    sort(d, d+n);
    for (int i = 1; i < n; i++)
        cout << d[i] << " ";
    cout << "\n";
}