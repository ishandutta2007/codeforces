#include <bits/stdc++.h>

using namespace std;

int n, m, x[200020], t[200020], clo[200020], ans[200020];

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n + m; i++) {
        scanf("%d", &x[i]);
    }
    for(int i = 0; i < n + m; i++) {
        scanf("%d", &t[i]);
    }
    int last = -1;
    for(int i = 0; i < n + m; i++) {
        if(t[i] == 1) last = i;
        clo[i] = last;
    }
    last = -1;
    for(int i = n + m - 1; i >= 0; i--) {
        if(t[i] == 1) last = i;
        if(clo[i] == -1 || (last != -1 && abs(x[i] - x[last]) < abs(x[i] - x[clo[i]])))
            clo[i] = last;
    }
    for(int i = 0; i < n + m; i++) {
        if(!t[i]) ans[clo[i]]++;
    }
    for(int i = 0; i < n + m; i++)
        if(t[i]) printf("%d ", ans[i]);
    return 0;
}