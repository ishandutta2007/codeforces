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

string s;
int p[100005], n;
int cnt[100005] = {};
int ans1[100005], ans2[100005], ansc = 0;

int main() {
    cin >> s;
    n = s.length();
    p[0] = 0;
    for (int i = 1; i < n; ++i) {
        int cur = p[i - 1];
        while (cur && s[i] != s[cur])
            cur = p[cur - 1];
        if (s[i] == s[cur])
            ++cur;
        p[i] = cur;
    }
    REP(i, n)
        ++cnt[p[i]];
    for (int i = n - 1; i > 0; --i)
        cnt[p[i - 1]] += cnt[i];
    int cur = p[n - 1];
    while (cur) {
        ans1[ansc] = cur;
        ans2[ansc++] = cnt[cur] + 1;
        cur = p[cur - 1];
    }
    printf("%d\n", ansc + 1);
    for (int i = ansc - 1; i >= 0; --i)
        printf("%d %d\n", ans1[i], ans2[i]);
    printf("%d %d\n", n, 1);
    return 0;
}