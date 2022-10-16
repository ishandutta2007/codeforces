#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 
#include <tuple>

using namespace std;

int n, invs, m, k;
const int mod = 1000000007;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    int ans = 1;

    if (k > n || k == 1) {
        for (int i = 0; i < n; i++) {
            ans = (ans * 1ll * m) % mod;
        }
    }
    else if (k == n) {
        for (int i = 0; i < (n+1)/2; i++) {
            ans = (ans * 1ll * m) % mod;
        }
    }
    else if (k < n && k % 2 == 1) {
        ans = (m * 1ll * m) % mod;
    }
    else {
        ans = m % mod;
    }

    cout << ans << endl;

}