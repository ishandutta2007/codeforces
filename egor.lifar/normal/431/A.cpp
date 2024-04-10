#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>


using namespace std;


string s;
int a[4];
int ans = 0;


int main() {
    cin >> a[0] >> a[1] >> a[2] >> a[3];
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        ans += a[int(s[i] - '0' - 1)];
    }
    cout << ans << endl;
    return 0;
}