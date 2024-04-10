#include <bits/stdc++.h>

using namespace std;

int h, m;

bool pal(int h, int m) {
    return (((h % 10) == (m / 10)) && (h / 10) == (m % 10));
}

int main() {
    scanf("%d:%d", &h, &m);
    int ans = 0;
    while(!pal(h, m)) {
        m++;
        if(m == 60) {
            m = 0;
            h++;
            if(h == 24)
                h = 0;
        }
        ans++;
    }
    printf("%d\n", ans);
}