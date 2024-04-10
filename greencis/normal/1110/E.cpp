#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[100105];
multiset<int> p, q;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    int z = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) p.insert(a[i] - a[i - 1]);
        else z^=*a;
    }
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i > 0) q.insert(a[i] - a[i - 1]);
        else z^=*a;
    }
    cout << (p == q && !z ? "Yes" : "No") << endl;
}