#include <bits/stdc++.h>

using namespace std;

char s[100010]; string str;

int main() {
    while(1) {
        scanf("%s", s); str = s;
        if(str != "start") break;


        int L = 0, R = 1;
        while(1) {
            printf("? %d %d\n", L, R);
            fflush(stdout);

            scanf("%s", s);
            if(s[0] == 'x') break;
            L = R; R *= 2;
        }

        int l = L+1, r = R, m;
        while(l < r) {
            m = (l + r) / 2;
            printf("? %d %d\n", m, R);
            fflush(stdout);

            scanf("%s", s);
            if(s[0] == 'x') l = m + 1;
            else r = m;
        }

        printf("! %d\n", l);
        fflush(stdout);
    }
    return 0;
}