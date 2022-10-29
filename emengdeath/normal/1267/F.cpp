#include <bits/stdc++.h>
#define N 200002
using namespace std;
int n, m, na, nb, a[N], b[N], c[N];
priority_queue<int> h;
queue<pair<int, int> > ans;
int main() {
    scanf("%d%d%d%d", &n, &m, &na, &nb);
    for(int i = 1; i <= na; ++ i) scanf("%d", &a[i]);
    for(int i = 1; i <= nb; ++ i) scanf("%d", &b[i]);
    if(na >= m || nb >= n) puts("No");
    else {
        puts("Yes");
        while(!ans.empty()) ans.pop();
        for(int i = na + 1; i < m; ++ i) a[i] = 1;
        for(int i = nb + 1; i < n; ++ i) b[i] = n + 1;
        for(int i = 1; i < m; ++ i) ++ c[a[i]];
        for(int i = 1; i < n; ++ i) ++ c[b[i]];
        for(int i = 1; i <= n + m; ++ i)
            if(!c[i]) h.push(-i);
        for(int i = 1, j = 1; i < m || j < n; ) {
            int x = -h.top();
            h.pop();
            if(x > n) {
                ans.push(make_pair(x, a[i]));
                if(!-- c[a[i]]) h.push(-a[i]);
                ++ i;
            } else {
                ans.push(make_pair(x, b[j]));
                if(!-- c[b[j]]) h.push(-b[j]);
                ++ j;
            }
        }
        int x = -h.top();
        h.pop();
        int y = -h.top();
        h.pop();
        ans.push(make_pair(x, y));
        while(!ans.empty()) {
            printf("%d %d\n", ans.front().first, ans.front().second);
            ans.pop();
        }
    }
}