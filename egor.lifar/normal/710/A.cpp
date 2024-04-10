 #include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <cstring>
#include <cmath>
#include <unordered_map>
#include <cassert>


using namespace std;


string s;


int main() {
    cin >> s;
    int a = s[0] - 'a' + 1;
    int b = s[1] - '0';
    int cnt = 0;
    if (a > 1 && b > 1) {
        cnt++;
    }
    if (a > 1) {
        cnt++;
    }
    if (a > 1 && b < 8) {
        cnt++;
    }
    if (b < 8) {
        cnt++;
    }
    if (a < 8 && b < 8) {
        cnt++;
    }
    if (a < 8) {
        cnt++;
    }
    if (a < 8 && b > 1) {
        cnt++;
    }
    if (b > 1) {
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}