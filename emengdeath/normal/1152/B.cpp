#include <cstdio>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n;
int ans[100];
bool is_checked(int x)
{
    while (x){
        if ((x & 1) == 0) return 0;
        x >>= 1;
    }
    return 1;
}
int main()
{
    scanf("%d", &n);
    while (!is_checked(n))
    {
        if (ans[0] & 1) n++, ans[0] ++;
        else
        {
            int x = 1, sum = 0;
            while ((x << 1) <= n) x <<= 1, sum ++;
            sum ++;
            x = (x << 1) - 1;
            n ^= x;
            ans[++ans[0]] = sum;
        }
    }
    printf("%d\n", ans[0]);
    for (int i = 1; i <= ans[0]; i += 2)
        printf("%d ", ans[i]);
    return 0;
}