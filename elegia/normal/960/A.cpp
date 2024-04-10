#include <cstdio>

using namespace std;

typedef long long ll;

char s[5010];
int ca, cb, cc;

int main() {
    scanf("%s", s);
    for (char* p = s; *p; ++p) {
        if (*p == 'a') {
            ++ca;
        } else if (*p == 'b')
            ++cb;
        else
            ++cc;
        if (p != s && *p < *(p - 1)) {
            puts("NO");
            return 0;
        }
    }
    if (ca == 0 || cb == 0)
        puts("NO");
    else if (cc == ca || cc == cb)
        puts("YES");
    else
        puts("NO");
    return 0;
}