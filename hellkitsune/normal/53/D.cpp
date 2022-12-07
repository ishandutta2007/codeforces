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

int n;
int a[300], b[300];
vector<int> ans;

int main() {
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    REP(i, n) scanf("%d", b + i);
    REP(i, n) if (a[i] != b[i]) {
        int pos = -1;
        for (int j = i + 1; j < n; ++j) if (b[j] == a[i]) {
            pos = j;
            break;
        }
        for (int j = pos - 1; j >= i; --j) {
            swap(b[j], b[j + 1]);
            ans.pb(j + 1);
        }
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d %d\n", x, x + 1);
    return 0;
}