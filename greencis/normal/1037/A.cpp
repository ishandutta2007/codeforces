#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



int main() {
    ios_base::sync_with_stdio(false);

    int x;
    cin >> x;
    int ans = 0;
    while (x) {
        ++ans;
        x /= 2;
    }
    cout << ans << endl;
}