#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, a[55], u[1005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i], u[a[i]] = i;
    vector<int> v;
    for (int i = n; i >= 1; --i) {
        if (u[a[i]])
            v.push_back(a[i]), u[a[i]] = 0;
    }
    reverse(all(v));
    cout << v.size() << endl;
    for (int x : v)
        cout << x << " ";
}