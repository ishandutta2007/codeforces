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
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool fl = true;
    string ans;
    set <char> c = {'a', 'e', 'i', 'o', 'u', 'y'};
    for (int i = 0; i < n; ++i) {
        if (!c.count(s[i])) fl = true;
        if (fl) {
            ans += s[i];
        }
        if (c.count(s[i])) {
            fl = false;
        }
    }
    cout << ans << endl;
}