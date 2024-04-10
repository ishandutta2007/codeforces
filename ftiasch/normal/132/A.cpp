#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char text[111];

int reverse(int n) {
    int ret = 0;
    for (int i = 0; i < 8; ++ i) {
        ret = ret * 2 + ((n >> i) & 1);
    }
    return ret;
}

int main() {
    fgets(text, 111, stdin);
    n = strlen(text) - 1;
    for (int i = 0; i < n; ++ i) {
        int pre = reverse(i? text[i - 1]: 0);
        int cur = reverse(text[i]);
        printf("%d\n", ((pre - cur) % 256 + 256) % 256);
    }
    return 0;
}