#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 300005;
ll a[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    priority_queue<ll> p;
    ll out = 0;
    for (int i = 0; i < n; i++) {
        p.push(-a[i]); p.push(-a[i]);
        out += a[i]+p.top(); p.pop();
    }
    cout << out << "\n";
}