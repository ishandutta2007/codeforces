#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int a[2001], b[10];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]), a[i] ^= a[i - 1];
        bool sig = 0;
        for (int i = 1; i < n && ! sig; i ++) {
            if (a[i] == (a[n] ^ a[i])) sig = 1;
            for (int j = i + 1; j < n; j ++)
                if (a[i] == (a[j] ^ a[i]) && a[i] == (a[n] ^ a[j])) sig = 1;
        }
        sig ? puts("YES"):puts("NO");
    }
}