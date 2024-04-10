#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


int n;
int m;
int ans = 0;


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int b;
        cin >> b;
        if (b >= 0) {
            m += b;
        } else {
            if (m > 0) {
                m--;
            } else {
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}