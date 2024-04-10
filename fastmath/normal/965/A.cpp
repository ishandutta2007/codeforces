#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int k, n, s, p;
    cin >> k >> n >> s >> p;

    int want = (n - 1) / s + 1;
    want *= k;
    cout << (want - 1) / p + 1; 

    return 0;
}