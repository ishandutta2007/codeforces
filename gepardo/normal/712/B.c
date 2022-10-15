#include <stdio.h>
#include <math.h>
#define min(a, b) (((a) < (b)) ? (a) : (b))
#define max(a, b) (((a) < (b)) ? (a) : (b))
#define INFINITE 123456789

int main()
{
    static char s[1000000];
    gets(s);
    int c_u = 0, c_d = 0, c_l = 0, c_r = 0;
    char *c = s;
    for (; *c; c++)
        switch (*c)
        {
            case 'U': c_u++; break;
            case 'D': c_d++; break;
            case 'L': c_l++; break;
            case 'R': c_r++; break;
        }
    int sum = c_u + c_d + c_l + c_r,
        hsum = sum / 2;
    if (sum % 2)
    {
        puts("-1");
        return 0;
    }
    int ans = INFINITE;
    int i = 0;
    for (; i <= hsum; i++)
    {
        int j = hsum - i;
        ans = min(ans, (abs(c_u - i) + abs(c_d - i) + abs(c_l - j) + abs(c_r - j)) / 2);
    }
    printf("%d\n", ans);
}