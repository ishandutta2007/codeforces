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

typedef long long ll;

ll n, k;
int p;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;

    cin >> p;
    for (; p; p--) {
        ll pos;
        cin >> pos;

        if (k == 0) {
            cout << '.';
            continue;
        }
        if (n % 2 == 1 && pos == n) {
            cout << 'X';
            continue;
        }

        ll tn = n - (n%2);
        pos = tn - pos;
        ll tk = k - (n%2);

//        cout << pos;
        if (pos % 2 == 0 && pos/2 < tk) cout << 'X';
        else if (pos % 2 == 1 && pos/2 + (n/2) < tk) cout << 'X';
        else cout << '.';
    }
}