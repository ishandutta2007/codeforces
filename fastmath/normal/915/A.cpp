#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main(){
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    int ans = MOD;
    for (int i = 0; i < n; ++i){
        int len;
        cin >> len;
        if (k % len == 0) ans = min(ans, k / len);
    }

    cout << ans << '\n';
    return 0;
}