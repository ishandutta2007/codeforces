#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <vector>


using namespace std;


int n;


int main() {
    cin >> n;
    int ans = 0;
    while (true) {
        n++;
        ans++;
        bool b = false;
        int n1 = abs(n);
        while (n1 > 0) {
            if (n1 % 10 == 8) {
                b = true;
            }
            n1 /= 10;
        }
        if (b) {
            cout << ans << endl;
            return 0;
        }
    }
    return 0;
}