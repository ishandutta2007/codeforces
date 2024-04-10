#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <cassert>



using namespace std;


long long m;
pair<long long, long long> best;


long long mypow(int x) {
    return 1LL * x * x * x;
}


void rec(long long m, long long steps, long long subtracted) {
    if (m == 0) {
        best = max(best, make_pair(steps, subtracted));
        return;
    }
    int c = 1;
    while (mypow(c + 1) <= m) {
        c++;
    }
    rec(m - mypow(c), steps + 1, subtracted + mypow(c));
    if (c - 1 >= 0) {
        rec(mypow(c) - 1 - mypow(c - 1), steps + 1, subtracted + mypow(c - 1));
    }
}


int main() {
    cin >> m;
    rec(m, 0, 0);
    cout << best.first << ' ' << best.second << endl;
    return 0;   
}