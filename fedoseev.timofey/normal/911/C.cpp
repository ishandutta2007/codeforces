#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    if (k1 == 1 || k2 == 1 || k3 == 1) {
        cout << "YES" << endl;
        return 0;
    }
    if (k1 == 3 && k2 == 3 && k3 == 3) {
        cout << "YES" << endl;
        return 0;
    }
    int cnt2 = 0, cnt4 =0;
    if (k1 == 2) ++cnt2;
    if (k2 == 2) ++cnt2;
    if (k3 == 2) ++cnt2;
    if (k1 == 4) ++cnt4;
    if (k2 == 4) ++cnt4;
    if (k3 == 4) ++cnt4;
    if (cnt2 >= 2) {
        cout << "YES" << endl;
        return 0;
    }
    if (cnt2 == 1 && cnt4 == 2) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    return 0;
}