#include <bits/stdc++.h>
using namespace std;

// #define int long long
// #define double long double

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 3e5+5;
const int inf = 0x3f3f3f3f;


int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie();
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int qntLo = 0;
        int lo = 321;
        for(int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x < lo) {
                lo = x;
                qntLo = 1;
            } else if(x == lo) qntLo++;
        }
        cout << n - qntLo << '\n';
    }
    return 0;
}