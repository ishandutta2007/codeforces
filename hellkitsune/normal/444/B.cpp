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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

LL x;
int n, d;
int a[100000], b[100000];
priority_queue<PII> q;
PII v[100002];
int vs;
vector<int> c;

int getNextX() {
    x = (x * 37 + 10007) % 1000000007;
    return (int) x;
}

void initAB() {
    for(int i = 0; i < n; i = i + 1){
        a[i] = i + 1;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(a[i], a[getNextX() % (i + 1)]);
    }
    for(int i = 0; i < n; i = i + 1){
        if (i < d)
            b[i] = 1;
        else
            b[i] = 0;
    }
    for(int i = 0; i < n; i = i + 1){
        swap(b[i], b[getNextX() % (i + 1)]);
    }
}

int main() {
    cin >> n >> d >> x;
    initAB();
    if ((LL) d * d < n * 36) {
        REP(i, n) if (b[i] == 1) c.pb(i);
        REP(i, n) {
            int ans = 0;
            int l = -1, r = c.size() - 1, mid;
            while (l < r) {
                mid = (l + r + 1) >> 1;
                if (i < c[mid])
                    r = mid - 1;
                else
                    l = mid;
            }
            int f = l;
            for (int j = 0; j <= f; ++j)
                ans = max(ans, a[i - c[j]]);
            printf("%d\n", ans);
        }
        return 0;
    }
    REP(i, n) {
        q.push(mp(a[i], i));
        vs = 0;
        int ans = 0;
        while (!q.empty()) {
            int z = q.top().second;
            if (b[i - z] == 0) {
                v[vs++] = q.top();
                q.pop();
            } else {
                ans = a[z];
                break;
            }
        }
        REP(j, vs) q.push(v[j]);
        printf("%d\n", ans);
    }
    return 0;
}