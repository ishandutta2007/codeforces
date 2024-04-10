#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
char s[100000];
int n;
void del_str(int st, int len) {
    for (int i = st; i + len < n; i ++)
        s[i] = s[i + len];
    n -= len;
}
int main() {
    scanf("%s", s);
    n = strlen(s);
    int len = 1;
    while (len * 2 <= n) {
        int cnt = 0;
        bool sig = 0;
        for (int i = 0; i + len < n; i ++) {
            if (s[i] == s[i + len])
                cnt ++;
            else
                cnt = 0;
            if (cnt == len) {
                for (int j = 0; j < len; j ++)
                    s[i - j] = -1;
                cnt = 0;
                sig = 1;
            }
        }
        if (sig) {
            cnt = n;
            n = 0;
            for (int i = 0; i < cnt; i++)
                if (s[i] != -1)
                    s[n++] = s[i];
        }
        len ++;
    }
    s[n] = 0;
    printf("%s", s);
    return 0;
}