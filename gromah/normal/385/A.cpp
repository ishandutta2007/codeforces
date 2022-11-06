#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 100 + 5
int n, c, ans, w[N];
void begin()
{
    scanf("%d%d", &n, &c);
    for (int i = 1; i <= n; i ++)
        scanf("%d", w + i), ans = max(ans, w[i - 1] - w[i] - c);
}
void work()
{
    
}
void end()
{
    printf("%d\n", ans);
}
int main()
{
    begin();
    work();
    end();
    return 0;
}