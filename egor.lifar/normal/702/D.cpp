#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>


using namespace std;


long long d, k, a, b, t, c;

    
int main() {
    cin >> d >> k >> a >> b >> t;
    if (d <= k) {
        cout << d * a << endl;
        return 0;
    }
    if (t + k * a > k * b) {
        cout << k * a + (d - k) * b << endl;
        return 0;
    }
    long long cnt = d / k;
    cout << k * cnt * a + (cnt - 1LL) * t + min(t + (d % k) * a, (d % k) * b) << endl;
    return 0;
}