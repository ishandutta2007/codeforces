#include <bits/stdc++.h>

using namespace std;

int n, d[110], tval;

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%1d", &d[i]);
        tval += d[i];
    }

    for(int sum = 0; sum <= tval; sum++) {
        int parts = 0, tmp = 0, flag = 1;
        for(int i = 1; i <= n && flag; i++) {
            tmp += d[i];
            if(tmp == sum) {
                parts++;
                tmp = 0;
            } else if(tmp > sum) flag = 0;
        }
        if(tmp) flag = 0;
        if(flag && parts > 1) {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}