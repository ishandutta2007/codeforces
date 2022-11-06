#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int N = 130621;
int len[4];
char s[4][N];
bool ok(int k)
{
    bool ok1 = 1, ok2 = 1;
    for (int i = 0; i < 4; i ++)
        if (i != k && len[i] < (len[k] << 1))
        {
            ok1 = 0;
            break ;
        }
    for (int i = 0; i < 4; i ++)
        if (i != k && len[k] < (len[i] << 1))
        {
            ok2 = 0;
            break ;
        }
    return ok1 | ok2;
}
int main()
{
    for (int i = 0; i < 4; i ++)
    {
        scanf("%s", s[i]);
        len[i] = strlen(s[i]) - 2;
    }
    char tmp = '\0';
    for (int i = 0; i < 4; i ++)
        if (ok(i))
        {
            if (tmp != '\0')
            {
                tmp = 'C';
                break;
            }
            tmp = i + 'A';
        }
    if (tmp == '\0') tmp = 'C';
    printf("%c\n", tmp);
    return 0;
}