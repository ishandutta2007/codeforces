#include <iostream>
#include <cstdio>
using namespace std;

const int N = 100005;

int n, pre, cur, ans, cnt = 0;

int main()
{
    scanf("%d%d", &n, &cur);
    while (n--)
    {
        scanf("%d", &cur);
        ans = max(ans, cnt = (cur == pre ? 1 : cnt + 1));
        pre = cur;
    }
    printf("%d", ans);
}