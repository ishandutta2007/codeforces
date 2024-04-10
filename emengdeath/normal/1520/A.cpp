#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
char s[10000];
int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);
        bool sig = 1;
        for (int i = 0; i < n; i ++)
            for (int j = i + 1; j < n; j ++)
                if (s[i] == s[j] && s[j - 1] != s[i]) sig = 0;
        sig?puts("YES"):puts("NO");
    }
    return 0;
}