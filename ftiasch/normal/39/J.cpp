// School Team Contest #1
// Problem J -- Spelling Check
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1111111;
const int BASE = 217;

int n, m;
char s[N], p[N];
bool res[N];
unsigned long long preHash[N], sufHash[N], power[N];

int main () {
    scanf("%s%s", s + 1, p + 1);
    n = strlen(s + 1);
    m = strlen(p + 1);
    power[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        power[i] = power[i - 1] * BASE;
    }
    preHash[0] = 0;
    for (int i = 1; i <= n; ++ i) {
        preHash[i] = preHash[i - 1] + power[i - 1] * s[i];
    }
    sufHash[n + 1] = 0;
    for (int i = n; i >= 1; -- i) {
        sufHash[i] = sufHash[i + 1] * BASE + s[i];
    }    
    unsigned long long patHash = 0;
    for (int i = 1; i <= m; ++ i) {
        patHash += p[i] * power[i - 1];
    }
    memset(res, 0, sizeof(res));
    int tot = 0;
    for (int i = 1; i <= n; ++ i) {
        if (preHash[i - 1] + power[i - 1] * sufHash[i + 1] == patHash) {
            tot += 1;
            res[i] = true;
        }
    }
    printf("%d\n", tot);
    if (tot) {
        for (int i = 1; i <= n; ++ i) {
            if (res[i]) {
                printf("%d%c", i, -- tot == 0? '\n': ' ');
            }
        }
    }
    return 0;
}