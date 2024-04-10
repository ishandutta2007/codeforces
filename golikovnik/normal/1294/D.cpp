#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    map<int, int> have;
    int mex = 0;
    int q, x;
    cin >> q >> x;
    while (q--) {
        int y;
        cin >> y;
        ++have[y % x];
        while (have[mex % x] >= (mex / x + 1)) ++mex;
        cout << mex << '\n';
    }
}