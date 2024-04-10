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


int n, k;


bool prosto(int x) {
    int s = 1;
    int ans = x;
    s *= k;
    while (x / s > 0) {
        ans += x / s;
        s *= k;
    }
    return ans >= n;
}


int main() {
    cin >> n >> k;
    int l = 1;
    int r = n;
    while (l != r) {
        int m = (l + r) / 2;
        if (prosto(m)) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    cout << l << endl;
    return 0;
}