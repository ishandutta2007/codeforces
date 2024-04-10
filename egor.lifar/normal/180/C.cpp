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
string s;
int up, down;
int ans;


int main() {
    cin >> s;
    n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            up++;
        }
    }
    if (up == n || up == 0) {
        cout << 0 << endl;
        return 0;
    }
    ans = up;
    for (int i = 0; i < n; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            down++;
        } else {
            up--;
        }
        ans = min(ans, up + down);
    }
    cout << ans << endl;
    return 0;
}