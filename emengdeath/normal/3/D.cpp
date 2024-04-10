#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 1e5;
char s[N];
int n;
long long ans;
int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    priority_queue<pair<int, int> > q;
    int v = 0;
    for (int i = 1; i <= n; i ++) {
        switch (s[i]) {
            case '(':
                v ++;
                break;
            case ')':
                v --;
                break;
            case '?':
                v --;
                s[i] = ')';
                int a, b;
                scanf("%d %d", &a, &b);
                ans += b;
                q.push({b - a, i});

        }
        if (v < 0 ) {
            if (q.empty()) {
                puts("-1");
                return 0;
            }
            v += 2;
            ans -= q.top().first;
            s[q.top().second] = '(';
            q.pop();
        }
    }
    v?puts("-1"):printf("%lld\n%s\n", ans, s + 1);
    return 0;
}