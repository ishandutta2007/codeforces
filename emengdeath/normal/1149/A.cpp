#include <cstdio>
#include <unordered_map>
#include <algorithm>
#include <map>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
const int N = 2000001;
int n, k;
int a[N], d[N], sum[3], sum1[3];
int ans[N], ans1[N];
bool isPrime(int x)
{
    if (x == 1) return 0;
    return d[a[x]] == x;
}
void work(int x)
{
    while (x <= n)
    {
        if (sum1[1] && isPrime(ans1[x - 1] + 1))
        {
            ans1[x] = ans1[x - 1] + 1;
            ans1[0] ++;
            sum1[1] --;
        } else
        if (sum1[2] && isPrime(ans1[x -1] + 2))
        {
            ans1[x] = ans1[x - 1] + 2;
            ans1[0]++;
            sum1[2] --;
        } else
            if (sum1[2])
            {
                ans1[x] = ans1[x - 1] + 2;
                sum1[2]--;
            } else{
                ans1[x] = ans1[x - 1] + 1;
                sum1[1] --;
            }
        x ++;
    }
}
int main()
{
    for (int i = 2; i < N ;  i ++)
    {
        if (!a[i])
            d[a[i] = ++d[0] ] = i;
        for (int j = 1; j <= a[i] && (long long) i * d[j] < N; j ++)
            a[d[j] * i] = j;
    }
    scanf("%d", &n);
    for (int i = 1; i <= n ; i ++)
    {
        int x;
        scanf("%d", &x);
        ans[i] = x;
        sum[x] ++;
    }
    ans[0] = 0;
    sum1[1] = sum[1];
    sum1[2] = sum[2];
    if (sum1[2] ) {
        ans1[0] = 1;
        ans1[1] = 2;
        sum1[2]--;
        work(2);
        if (ans1[0] > ans[0])
        {
            for (int i = 0; i <= n ; i ++)
                ans[i] = ans1[i];
        }
    }
    sum1[1] = sum[1];
    sum1[2] = sum[2];
    if (sum1[1])
    {
        ans1[0] = 0;
        ans1[1] = 1;
        sum1[1]--;
        work(2);
        if (ans1[0] > ans[0])
        {
            for (int i = 0; i <= n ; i ++)
                ans[i] = ans1[i];
        }
    }
    ans[0] = 0;
    for (int i = 1; i <= n ; i ++)
        printf("%d ", ans[i] - ans[i -  1]);
    return 0;
}