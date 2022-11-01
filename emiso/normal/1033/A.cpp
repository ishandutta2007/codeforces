#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll n, ax, ay, bx, by, cx, cy;

void cant() {
    puts("NO");
    exit(0);
}

int main() {
    scanf("%lld", &n);
    scanf("%lld %lld", &ax, &ay);
    scanf("%lld %lld", &bx, &by);
    scanf("%lld %lld", &cx, &cy);

    while(bx != cx) {
        if(bx == ax) cant();
        if(by == ay) cant();

        if(bx < cx) bx++;
        else bx--;
    }

    while(by != cy) {
        if(bx == ax) cant();
        if(by == ay) cant();

        if(by < cy) by++;
        else by--;
    }

    puts("YES");
    return 0;
}