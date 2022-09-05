#include <bits/stdc++.h>
using namespace std;

const int maxn = 150000;
int n;
struct rect {
    int x1, y1, x2, y2;
    rect() { x1 = y1 = INT_MIN, x2 = y2 = INT_MAX; }
} a[maxn], pre[maxn], suf[maxn];

rect inter(rect A, rect B) {
    rect C;
    C.x1 = max(A.x1, B.x1);
    C.x2 = min(A.x2, B.x2);
    C.y1 = max(A.y1, B.y1);
    C.y2 = min(A.y2, B.y2);
    return C;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d %d", &a[i].x1, &a[i].y1, &a[i].x2, &a[i].y2);
        pre[i] = inter(pre[i - 1], a[i]);
    }
    for (int i = n; i; i--) {
        suf[i] = inter(suf[i + 1], a[i]);
    }
    for (int i = 1; i <= n; i++) {
        rect b = inter(pre[i - 1], suf[i + 1]);
        if (b.x1 <= b.x2 && b.y1 <= b.y2) printf("%d %d\n", b.x1, b.y1), exit(0);
    }
    return 0;
}