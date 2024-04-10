#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, k, A, B;
    cin >> n >> k >> A >> B;
    if (k == 1) {
        cout << (ll)(n - 1) * A << endl;
        return 0;
    }
    ll ans = 0;
    while (n > 1) {
        int cur = n % k;
        if (n == cur) {
            ans += (ll)A * (cur - 1);
            break;
        }
        if (cur != 0) {
            ans += (ll)cur * A;
            n -= cur;
        }
        else {
            int tmp = n / k;
            if ((ll)A * (n - tmp) < B) {
                ans += (ll)A * (n - tmp);
            }
            else {
                ans += B;
            }
            n = tmp;
        }
    }
    cout << ans << endl;
}