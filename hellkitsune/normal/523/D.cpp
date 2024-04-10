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

priority_queue<LL, vector<LL>, greater<LL> > q;
int n, k;
LL pos, len;

int main() {
    scanf("%d%d", &n, &k);
    REP(i, n) {
        scanf("%I64d%I64d", &pos, &len);
        if ((int)q.size() == k) {
            pos = max(pos, q.top());
            q.pop();
        }
        printf("%I64d\n", pos + len);
        q.push(pos + len);
    }
    return 0;
}