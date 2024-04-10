#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 300;
char s[N];
int write(char * s, int len) {
    for (int i = 0; i < len ; i++)
        putchar(s[i]);
    putchar('\n');
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x;
}
int main() {
    for (int i = 0; i < 300; i ++)
        s[i] = 'a';
    int suma = 300 - write(s, 300);
    for (int i = 0; i < 300; i ++)
        s[i] = 'b';
    int sumb = 300 - write(s, 300);
    int n = suma + sumb;
    if (sumb == 0) {
        for (int i = 0; i < n; i ++)
            s[i] = 'a';
        write(s, n);
        return 0;
    }
    if (suma == 0) {
        for (int i = 0; i < n; i ++)
            s[i] = 'b';
        write(s, n);
        return 0;
    }
    for (int i = 0; i < n; i ++)
        s[i] = 'a';
    int last = sumb;
    for (int i = 0; i < n; i ++) {
        s[i] = 'b';
        int x = write(s, n);
        if (!x) {
            return 0;
        }
        if (last > x) {
            last = x;
            continue;
        }
        s[i] = 'a';
    }
    return 0;
}