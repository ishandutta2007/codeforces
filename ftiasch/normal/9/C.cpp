// Codeforces Beta Round #9
// Problem C -- Hexadecimal's Numbers
#include <cstdio>
#include <cstring>

using namespace std;

int n, s[10], p[10];
bool v[11];

int main()
{
    int l = 0;
    for(scanf("%d", &n), n ++; n > 0; n /= 10)
        s[l ++] = n % 10;
    p[0] = 1;
    for(int i = 1; i != 10; ++ i)
        p[i] = p[i - 1] * 2;
    int a = 0;
    for(int i = 1; i != l; ++ i)
        a += p[i - 1];
    memset(v, 0, sizeof(v));
    for(int i = l - 1; i != -1; -- i)
        v[i] = v[i + 1] || (s[i] > 1);
    for(int i = 0; i != l; ++ i)
    {
        if(v[i + 1])
            continue;
        if(s[i] > 1)
            a += p[i];
        if(s[i] > 0 && i != l - 1)
            a += p[i];
    }
    printf("%d\n", a);
    return 0;
}