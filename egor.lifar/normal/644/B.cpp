#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <set>


using namespace std;


long long n, b;
long long t[200002], d[200002];
long long ans[200002];


int main() {
    cin >> n >> b;
    for (int i = 0; i < n; i++) {
        scanf("%d %I6d", &t[i], &d[i]);
        ans[i] = -1;
    }
    queue<int> q;
    long long curtime = 0;
    for (int i = 0; i < n; i++) {
        if (!q.empty()) {
            curtime = max(curtime, t[q.front()]);
        }
        while (!q.empty() && curtime + d[q.front()] <= t[i]) {
            ans[q.front()] = curtime + d[q.front()];
            curtime += d[q.front()];
            q.pop();
            if (!q.empty()) {
                curtime = max(curtime, t[q.front()]);
            }
        }
        if (q.empty()) {
            if (curtime < t[i]) {
                curtime = t[i];
            }
            q.push(i);
        } else {
            if (curtime <= t[i]) {
                curtime += d[q.front()];
                ans[q.front()] = curtime;
                q.pop();
            }
            if ((int)q.size() < b) {
                q.push(i);
            }
        }
    }
    if (!q.empty()) {
        curtime = max(curtime, t[q.front()]);
    }
    while (!q.empty()) {
        ans[q.front()] = curtime + d[q.front()];
        curtime += d[q.front()];
        q.pop();
        if (!q.empty()) {
            curtime = max(curtime, t[q.front()]);
        }
    }
    for (int i = 0; i < n; i++) {
        printf("%I64d ", ans[i]);
    }
    printf("\n");
    return 0;
}