#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cout << #x << ": <" << x << ">\n"
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int l = *min_element(a, a+n), h = *max_element(a, a+n);
    cout << (l == h ? 0 : n - count(a, a+n, l) - count(a, a+n, h));

    return 0;
}