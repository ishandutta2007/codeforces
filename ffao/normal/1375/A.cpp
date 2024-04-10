#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    for (cin >> t; t; t--) {
        int n; 
        for (cin >> n; n; n--) {
            int v; cin >> v;

            if (n % 2 == 0) cout << abs(v) << " ";
            else cout << -abs(v) << " ";
        }
        cout << endl;
    }

    return 0;
}