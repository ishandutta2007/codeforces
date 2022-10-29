#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll x, a[] = {3, 15, 81, 6723, 50625, 2562991875LL};
int sg[] = {0, 1, 2, 0, 3, 1, 2}, n, ans = 0;

int main() {

    cin >> n;
    while (n--) {
        cin >> x;
        ans ^= sg[lower_bound(a, a+6, x)-a];
    }
    cout << (ans ? "Furlo" : "Rublo") << endl;

    return 0;
}