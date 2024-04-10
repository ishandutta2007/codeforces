#include <cstdio>
#include <cstring>

const int N = 5000;

char s[N + 1];

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    int result = 0;
    for (int i = 0; i < n; ++ i) {
        int mi = 0;
        int ma = 0;
        for (int j = i; j < n; ++ j) {
            if (s[j] == '(') {
                mi ++;
                ma ++;
            } else if (s[j] == ')') {
                mi --;
                ma --;
            } else {
                mi --;
                ma ++;
            }
            if (mi < 0) {
                mi += 2;
            }
            if (mi > ma) {
                break;
            }
            result += mi == 0;
        }
    }
    printf("%d\n", result);
}