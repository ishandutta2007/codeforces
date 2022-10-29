#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int ans;
char s[1000000];
int T;
int main() {
    scanf("%d", &T);
    while (T --) {
        int sum[2] = {0, 0};
        scanf("%s", s);
        ans = 0;
        int n = strlen(s);
        for (int i = 0; i < n;i ++)
        {
            switch (s[i]) {
                case  '(':
                    sum[0]++;
                    break;
                case ')':
                    if (sum[0]) ans ++, sum[0] --;
                    break;
                case '[':
                    sum[1] ++;
                    break;
                case ']':
                    if (sum[1]) sum[1] --, ans ++;
                    break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}