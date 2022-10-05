#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <list>
#include <time.h>
#include <math.h>
#include <random>
#include <deque>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <iomanip>
#include <bitset>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int x = 0, y = 0;
    char last = '$';
    for (auto c : s) {
        if (x == y && c == last) ++ans;
        if (c == 'U') {
            ++y;
        }
        else if (c == 'R') {
            ++x;
        }
        last = c;
    }
    cout << ans << endl;
}