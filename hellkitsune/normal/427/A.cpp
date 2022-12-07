#include <cstdio>
#include <cmath>
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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, cur, sum = 0, ans = 0;

int main() {
    scanf("%d", &n);
    REP(i, n) {
        scanf("%d", &cur);
        sum += cur;
        if (sum < ans)
            ans = sum;
    }
    cout << -ans << endl;
    return 0;
}