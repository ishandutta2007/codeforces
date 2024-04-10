#include <iostream>
#include <sstream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <cstdio>
#include <cmath>
#include <string.h>
#include <cstring>
#include <map>
#include <set>
#include <queue>
#include <tuple>
#include <unordered_set>


using namespace std;


int n;
string s, s1;


int main() {
    cin >> n >> s >> s1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += min(min(s[i] - '0' + '9' - s1[i] + 1, abs(s[i] - s1[i])), s1[i] - '0' + '9' - s[i] + 1);
    }
    cout << ans << endl;
    return 0;
}