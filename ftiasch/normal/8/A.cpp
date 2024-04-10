// Codeforces Beta Round #8
#include <cstdio>
#include <cstring>
#include <algorithm>

#define n 100001

using namespace std;

char x[n], y[n], z[n];

int main()
{
    scanf("%s%s%s", x, y, z);
    bool f = strstr(x, y) && strstr(strstr(x, y) + strlen(y), z);
    reverse(x, x + strlen(x));
    bool b = strstr(x, y) && strstr(strstr(x, y) + strlen(y), z);
    if(f && b)
        printf("both\n");
    else
    if(!f && !b)
        printf("fantasy\n");
    else
        printf(f? "forward\n": "backward\n");
    return 0;
}