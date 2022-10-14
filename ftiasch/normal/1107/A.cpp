#line 1 "sol.cpp"
#include <bits/stdc++.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        int n;
        scanf("%d", &n);
        std::vector<char> s(n + 1);
        scanf("%s", s.data());
        if (n > 2) {
            printf("YES\n2\n%c %s\n", s[0], s.data() + 1);
        } else if (s[0] < s[1]) {
            printf("YES\n2\n%c %c\n", s[0], s[1]);
        } else {
            puts("NO");
        }
    }
}