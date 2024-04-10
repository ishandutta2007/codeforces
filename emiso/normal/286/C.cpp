#include <bits/stdc++.h>

using namespace std;

int n, p[1000100], t, q[1000100], ans[1000100];

int cant() {
    puts("NO");
    exit(0);
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &p[i]);
    }

    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        int x;
        scanf("%d", &x);
        q[x] = 1;
    }

    for(int i = n; i > 0; i--) {
        if(q[i] == 0) continue;

        stack<int> pia;
        while(1) {
            if(i == 0) cant();
            if(q[i] || p[i] != pia.top()) {
                pia.push(p[i]);
                ans[i] = -p[i];
            } else {
                pia.pop();
                ans[i] = p[i];
            }
            if(pia.empty()) break;
            i--;
        }
    }

    stack<int> pia;
    for(int i = n; i > 0; i--) {
        if(ans[i]) continue;
        if(pia.empty() || p[i] != pia.top()) {
            pia.push(p[i]);
            ans[i] = -p[i];
        } else {
            pia.pop();
            ans[i] = p[i];
        }
    }

    if(!pia.empty()) cant();

    puts("YES");
    for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}