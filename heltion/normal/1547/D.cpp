#include <bits/stdc++.h>
using namespace std;
struct P{
    int x, y;
};
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, p = 0;
        for (cin >> n; n; n -= 1){
            int x;
            cin >> x;
            cout << (p | x) - x << " ";
            p |= x;
        }
        cout << "\n";
    }
    return 0;
}