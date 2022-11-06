#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 20000 + 5
int n, sum, w[N];
bool ok = 0, f[N];
void begin()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", w + i), sum += w[i];
}
void work()
{
    if (sum % 2) return ;
    f[0] = 1;
    for (int i = 1; i <= n; i ++)
        for (int j = sum >> 1; j >= w[i]; j --)
            f[j] = f[j] | f[j - w[i]];
    ok = f[sum >> 1];
}
void end()
{
    printf("%s\n", ok == 1 ? "YES" : "NO");
}
int main()
{
    begin();
    work();
    end();
    return 0;
}