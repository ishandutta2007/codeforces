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

int n, k;
int b[1000];
vector<int> ans;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) scanf("%d", b + i);
    for (int i = n - 1; i >= 0; --i) {
        int pos = 0, x = b[i];
        while (x) {
            if (ans[pos] >= i + k) --x;
            ++pos;
        }
        ans.insert(ans.begin() + pos, i);
    }
    REP(i, n) printf("%d ", ans[i] + 1);
    printf("\n");
    return 0;
}