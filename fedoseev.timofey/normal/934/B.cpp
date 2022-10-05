#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <bitset>

using namespace std;

typedef long long ll;

int main() {
    ll k;
    cin >> k;
    if (k == 1) {
        cout << 4 << endl;
        return 0;
    }
    string s;
    while (k > 0) {
        if (k >= 2) {
            s += '8';
            k -= 2;
        }
        else {
            s += '0';
            --k;
        }
        if (s.size() > 18 || stoll(s) > (ll)1e18) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << s << endl;
}