#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int cnt[256];

void solve(int val) {
    char buf[256];
    scanf("%s", buf);
    int len = strlen(buf);
    for (int i = 0; i < len; ++ i) {
        cnt[(int)buf[i]] += val;
    }
}

int main() {
    memset(cnt, 0, sizeof(cnt));
    solve(1);
    solve(1);
    solve(-1);
    for (int i = 0; i < 256; ++ i) {
        if (cnt[i]) {
            puts("NO");
            return 0;
        }
    }
    puts("YES");
    return 0;
}