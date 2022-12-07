#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n;
string s;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> s;
    int dist = -1, pre = -1;
    REP(i, n) if (s[i] == '1') {
        if (pre == -1) {
            pre = i;
        } else {
            int cur = i - pre;
            pre = i;
            if (dist != -1 && dist != cur) {
                cout << "NO" << endl;
                return 0;
            }
            dist = cur;
        }
    }
    cout << "YES" << endl;
    return 0;
}