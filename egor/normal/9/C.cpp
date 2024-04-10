#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    char n[100];
    scanf("%s", n);
    bool w = false;
    int ans = 0;
    for (int i = 0; i < strlen(n); i++) {
        ans *= 2;
        if (w) {
            ans++;
            continue;
        }
        if (n[i] == '1')
            ans++;
        else if (n[i] > '1') {
            ans++;
            w = true;
        }
    }
    printf("%d\n", ans);
    return 0;
}