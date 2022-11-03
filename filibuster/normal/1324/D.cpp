#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;

void solve() {
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n;
    cin >> n;

    vector<int> x(n), y(n);
    for(int i = 0; i < n; i++)
        cin  >> x[i];

    for(int i = 0; i < n; i++)
        cin >> y[i];

    vector<int> a(n);
    for(int i = 0; i < n; i++)
        a[i] = x[i] - y[i];

    sort(a.begin(), a.end());

    li ans = 0;
    for(int i = 0; i < n; i++) {
        ans += (a.end() - lower_bound(a.begin(), a.end(), 1 - a[i]) );

        if(a[i] > 0)
            ans--;
//        cout << a[i] << ' ' << ans << endl;
    }

    cout << ans / 2;

}