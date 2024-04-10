// Codeforces Beta Round #7
// Problem D -- Palindrome Degree
#include <cstdio>
#include <cstring>

#define maxN 10000000
#define MIN(x, y) (x) < (y)? (x): (y)

using namespace std;

int n, m[maxN], d[maxN];
char s[maxN];

int main()
{
    scanf("%s", s);
    n = strlen(s);
    for(int i = 0; i < n; ++ i)
        s[n + i] = s[n - 1 - i];
    memset(m, 0, sizeof(m));
    for(int i = 1, j = 0; i < n + n; ++ i)
    {
        if(j + m[j] - 1 >= i)
            m[i] = MIN(j + m[j] - i, m[i - j]);
        while(i + m[i] < n + n && s[m[i]] == s[i + m[i]])
            m[i] ++;
        if(i + m[i] > j + m[j])
            j = i;
    }
    int a = d[0] = 1;
    for(int i = 1; i < n; ++ i)
        a += d[i] = (m[n + n - 1 - i] == i + 1)? d[((i + 1) >> 1) - 1] + 1: 0;
    printf("%d\n", a);
    return 0;
}