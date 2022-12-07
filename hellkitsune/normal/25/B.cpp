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
    ios_base::sync_with_stdio(false);
    cin >> n >> s;
    REP(i, n) {
        cout << s[i];
        if (i % 2 != n % 2 && i != 0 && i != n - 1) cout << '-';
    }
    cout << endl;
    return 0;
}