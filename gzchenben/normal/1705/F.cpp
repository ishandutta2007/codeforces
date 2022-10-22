#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
int n, cnt;
bool ans[1005];
int Ask()
{
    for (int i = 1; i <= n; i++)
    {
        printf(ans[i] ? "T" : "F");
    }
    printf("\n");
    fflush(stdout);
    int x = 0;
    // for (int i = 1; i <= n; i++)
    //     x += ans[i];
    scanf("%d", &x);
    // printf("%d\n", x);
    cnt++;
    // if (x == n)
    //     printf("cnt = %d\n", cnt);
    if (x == n)
        exit(0);
    if (x == -1)
        exit(1);
    return x;
}
int tot;
vector<int> vec;
void Solve(int L, int R, int x)
{
    if (x <= (R - L + 1) / 2)
    {
        tot += (R - L + 1) - x - x;
        x = (R - L + 1) - x;
        for (int i = L; i <= R; i++)
            ans[i] ^= 1;
    }
    if (x == (R - L + 1))
        return;
    // for (int i = 1; i <= n; i++)
    //     printf("%d", ans[i]);
    // printf("\nsolving %d %d %d %d\n", L, R, x, tot);
    if (R - L == 1)
    {
        vec.push_back(L);
        return;
    }
    int Mid = (L + R) / 2;
    for (int i = L; i <= Mid; i++)
        ans[i] ^= 1;
    int cur = Ask();
    for (int i = L; i <= Mid; i++)
        ans[i] ^= 1;
    int tmp1 = ((Mid - L + 1) - (cur - tot)) / 2;
    int tmp2 = x - tmp1;
    Solve(L, Mid, tmp1);
    Solve(Mid + 1, R, tmp2);
}
void work()
{
    if (!vec.size())
        return;
    int cur = 0;
    int nxt = 1;
    // printf("%d%d%d%d ", ans[1], ans[2], ans[3], ans[4]);
    while (nxt <= vec.size() - 1)
    {
        // printf("%d %d\n", vec[cur], vec[nxt]);
        ans[vec[cur]] ^= 1;
        ans[vec[nxt]] ^= 1;
        int tmp = Ask() - tot;
        ans[vec[cur]] ^= 1;
        ans[vec[nxt]] ^= 1;
        if (!tmp)
        {
            nxt++;
            continue;
        }
        if (tmp == 2)
        {
            ans[vec[cur]] ^= 1;
            ans[vec[nxt]] ^= 1;
            tot += 2;
            for (int i = cur + 1; i <= nxt - 1; i++)
            {
                ans[vec[i] + 1] ^= 1;
                tot++;
            }
        }
        if (tmp == -2)
        {
            ans[vec[cur] + 1] ^= 1;
            ans[vec[nxt] + 1] ^= 1;
            tot += 2;
            for (int i = cur + 1; i <= nxt - 1; i++)
            {
                ans[vec[i]] ^= 1;
                tot++;
            }
        }
        cur = nxt + 1;
        nxt = cur + 1;
    }
    if (cur > vec.size() - 1)
        return;
    ans[vec[cur]] ^= 1;
    int tmp = Ask() - tot;
    ans[vec[cur]] ^= 1;
    if (tmp == 1)
    {
        ans[vec[cur]] ^= 1;
        tot++;
        for (int i = cur + 1; i <= vec.size() - 1; i++)
        {
            ans[vec[i] + 1] ^= 1;
            tot++;
        }
    }
    else
    {
        ans[vec[cur] + 1] ^= 1;
        tot++;
        for (int i = cur + 1; i <= vec.size() - 1; i++)
        {
            ans[vec[i]] ^= 1;
            tot++;
        }
    }
}
int main()
{
    srand(123456);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ans[i] = rand() % 2;
    }
    tot = Ask();
    Solve(1, n, tot);
    // printf("siz = %d cnt = %d\n", vec.size(), cnt);
    work();
    Ask();
}