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
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
int cnt[101] = {};

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        for (int j = a; j <= b; ++j)
            ++cnt[j];
    }
    for (int i = 1; i <= n; ++i) if (cnt[i] != 1) {
        cout << i << ' ' << cnt[i] << endl;
        return 0;
    }
    cout << "OK" << endl;
    return 0;
}