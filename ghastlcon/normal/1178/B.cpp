#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define N 1000020
using namespace std;

int f[N];
char a[N];

int main(void)
{
    int n;
    int i;
    long long o;

    scanf("%s", a);
    n = strlen(a);
    for(i = 0; i < n - 1; i ++)
        if(a[i] == 'v' && a[i + 1] == 'v')
            f[i] = 1;
    for(i = 1; i < n; i ++)
        f[i] += f[i - 1];

    for(i = 1, o = 0; i < n - 1; i ++)
        if(a[i] == 'o')
            o += (long long)f[i] * (f[n - 1] - f[i]);
    cout << o << endl;

    return 0;
}