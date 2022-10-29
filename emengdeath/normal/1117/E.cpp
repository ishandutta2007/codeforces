#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 1e5;
char s[N];
char s1[N];
int n;
int fromid[N];
int main() {
    scanf("%s", s);
    n = strlen(s);
    for (int i = 0; i < n; i ++)
        s1[i] = (i % 26) + 'a';
    printf("? %s\n", s1);
    fflush(stdout);
    scanf("%s", s1);
    for (int i = 0; i < n; i ++)
        fromid[i] = s1[i] - 'a';

    for (int i = 0; i < n; i ++)
        s1[i] = (i / 26 % 26) + 'a';
    printf("? %s\n", s1);
    fflush(stdout);
    scanf("%s", s1);
    for (int i = 0; i < n; i ++)
        fromid[i] += 1ll * (s1[i] - 'a') * 26;


    for (int i = 0; i < n; i ++)
        s1[i] = (i / 26 / 26 % 26) + 'a';
    printf("? %s\n", s1);
    fflush(stdout);
    scanf("%s", s1);
    for (int i = 0; i < n; i ++)
        fromid[i] += 1ll * (s1[i] - 'a') * 26 * 26;
    for (int i = 0; i < n; i ++)
        s1[fromid[i]] = s[i];
    printf("! %s\n", s1);
    fflush(stdout);
    return 0;
}