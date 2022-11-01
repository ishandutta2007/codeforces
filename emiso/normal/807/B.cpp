#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int p, x, y;
//char s[MN]; string str;

bool ok(int s) {
    if(s < y) return false;

    s = ((s / 50) % 475);
    for(int i=0;i<25;i++) {
        s = ((s * 96 + 42) %  475);
        if(26 + s == p) return true;
    }

    return false;
}

int main() {
    scanf("%d %d %d", &p, &x, &y);
    int cx = x, h=0;

    while(cx >= y) {
        if(ok(cx)) {
            printf("0\n");
            return 0;
        }
        cx -= 50;
    }

    while(1) {
        if(ok(x) || ok(x - 50)) {
            printf("%d\n", h);
            return 0;
        }

        h += 1;
        x += 100;
    }
}