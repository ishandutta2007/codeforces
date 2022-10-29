#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int f[26], sum[26];
char s[1000];
int main(){
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%s", s);
        int n = strlen(s);
        memset(sum, 0, sizeof(sum));
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; i ++)
            sum[s[i] - 'a'] ++;
        scanf("%s", s);
        int m = strlen(s);
        bool sig1 = 0;
        for (int i = 0; i < m; i ++) {
            f[s[i] - 'a'] ++;
            if (i - n >= 0)
                f[s[i - n] - 'a'] --;
            bool sig = 1;
            for (int j = 0; j < 26; j ++)
                sig &= (f[j] == sum[j]);
            if (sig) {
                printf("YES\n");
                sig1=  1;
                break;
            }
        }
        if (!sig1) printf("NO\n");
    }
    return 0;
}