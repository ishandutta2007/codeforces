#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
#include <bitset>
using namespace std;

int n,k,a[1005],dp[1005],dm[1005],res=-2e9;
priority_queue<int> q,qm;

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        dp[i] = dp[i-1];
        dm[i] = dm[i-1];
        if (a[i] > 0)
            dp[i] += a[i];
        else dm[i] += a[i];
    }

    for (int st = 1; st <= n; ++st) {
        for (int f = st; f <= n; ++f) {
            int cur = dp[f] - dp[st-1] + dm[f] - dm[st-1];
            for (int i = 1; i <= n; ++i) {
                if (i < st || i > f) q.push(a[i]);
                else if (a[i] < 0) qm.push(-a[i]);
            }
            int kk = k;
            while (!q.empty() && q.top() > 0 && kk > 0) {
                cur += q.top();
                --kk;
                q.pop();
                if (qm.size()) {
                    cur += qm.top();
                    qm.pop();
                }
            }
            while (!q.empty()) q.pop();
            while (!qm.empty()) qm.pop();
            if (res < cur) res = cur;
        }
    }

    cout << res;

    return 0;
}