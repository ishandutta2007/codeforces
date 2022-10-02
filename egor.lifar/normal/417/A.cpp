#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int c, d, n, m, k;
int ans[100000];


int main() {
    cin >> c >> d >> n >> m >> k;
    int s = n * m - k;
    if (s <= 0) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 1; i <= s + n + k + 1; i++) {
        ans[i] = ans[i - 1] + d;
        if (i >= n) {
            ans[i] = min(ans[i], ans[i - n] + c);
        }
    }
    int t = 1000000000;
    for (int i = s; i <= s + n + k; i++) {
        t = min(t, ans[i]);
    }
    cout << t << endl;
    return 0;
}