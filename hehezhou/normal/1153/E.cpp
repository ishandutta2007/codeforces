#include <bits/stdc++.h>
using namespace std;
int line[1010], hei[1010], n;
vector<int> ansx, ansy;
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        printf("? %d %d %d %d\n", i, 1, i, n);
        fflush(stdout);
        scanf("%d", line + i);
        printf("? %d %d %d %d\n", 1, i, n, i);
        fflush(stdout);
        scanf("%d", hei + i);
    }
    for(int i = 1; i <= n; i++) if(line[i] & 1) ansx.push_back(i);
    for(int i = 1; i <= n; i++) if(hei[i] & 1) ansy.push_back(i);
    if(ansx.size() && ansy.size()) {
        printf("? %d %d %d %d\n", ansx[0], ansy[0], ansx[0], ansy[0]);
        fflush(stdout);
        int tag;
        scanf("%d", &tag);
        if(tag & 1) return printf("! %d %d %d %d\n", ansx[0], ansy[0], ansx[1], ansy[1]), fflush(stdout), 0;
        return printf("! %d %d %d %d\n", ansx[0], ansy[1], ansx[1], ansy[0]), fflush(stdout), 0;
    }
    if(ansx.size()) {
        int l = 1, r = n, ans;
        while(l <= r) {
            int tag, mid = l + r >> 1;
            printf("? %d %d %d %d\n", 1, 1, ansx[0], mid);
            fflush(stdout);
            scanf("%d", &tag);
            if(tag & 1) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return printf("! %d %d %d %d\n", ansx[0], ans, ansx[1], ans), fflush(stdout), 0;
    }
    int l = 1, r = n, ans;
    while(l <= r) {
        int tag, mid = l + r >> 1;
        printf("? %d %d %d %d\n", 1, 1, mid, ansy[0]);
        fflush(stdout);
        scanf("%d", &tag);
        if(tag & 1) ans = mid, r = mid - 1;
        else l = mid + 1;
    }
    return printf("! %d %d %d %d\n", ans, ansy[0], ans, ansy[1]), fflush(stdout), 0;
}