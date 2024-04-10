#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

int main() {
    ll n, k;
    cin >> n >> k;
    if (n == 1 && k == 1) {
        cout << "Yes" << endl;
        return 0;
    }
    for (ll i = 2; i <= min(k, (ll)1e8); ++i) {
        if ((n + 1) % i != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}