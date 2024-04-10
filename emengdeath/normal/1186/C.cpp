#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#define mod 1000000007
using namespace std;
char s[1000010], t[1000010];
int main()
{
    scanf("%s", s);
    scanf("%s", t);
    int lens = strlen(s);
    int lent = strlen(t);
    for (int i = 0; i < lens;  i ++)
        s[i] -= '0';
    for (int i = 1; i < lens;  i ++)
        s[i] ^= s[i - 1];
    for (int i = 0; i < lent; i ++)
        t[i] -= '0';
    for (int i = 0; i < lent; i ++)
        t[i] ^= t[i - 1];
    int ans = (t[lent - 1] == s[lent - 1]);
    for (int i = lent; i < lens; i  ++)
        ans += (t[lent - 1] == (s[i] ^ s[i - lent]));
    printf("%d\n", ans);
    return 0;
}