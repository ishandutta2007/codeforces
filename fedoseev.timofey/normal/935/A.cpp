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
    int ans = 0;
    for (int i = 1; i < n; ++i) {
        if ((n - i) % i == 0) ++ans;
    }
    cout << ans << endl;
}