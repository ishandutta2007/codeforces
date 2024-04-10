#include <cstdio>
const int MAX = 2e6+5;
bool chk[MAX];
int a[MAX], b[MAX];

void solveFirst(int n)
{
    printf("First\n");
    for (int i = 1; i <= n * 2; ++i)
        printf("%d ", i % n + 1);
    printf("\n");
    fflush(stdout);
}

void solveSecond(int n)
{
    printf("Second\n");
    fflush(stdout);
    for (int i = 1; i <= n * 2; ++i)
    {
        int id; scanf("%d", &id);
        id *= 2;
        chk[id] = !chk[id];
        if (chk[id])
            ++id;
        // printf("%d %d,", i, id);
        a[id] = i;
        b[i] = id;
    }
    long long sum = 0;
    for (int i = 1; i <= n; ++i)
        if (!chk[i] && !chk[i + n])
        {
            // printf("i %d ", i);
            int num = i;
            while (!chk[num])
            {
                // printf("j %d ", num);
                chk[num] = true;
                sum += num;
                num = a[b[num] ^ 1];
                if (num > n)
                    num -= n;
                else
                    num += n;
            }
        }
    if (sum / n % 2 == 1)
        for (int i = 1; i <= n * 2; ++i)
            chk[i] = !chk[i];
    for (int i = 1; i <= n * 2; ++i)
        if (chk[i])
            printf("%d ", i);
    printf("\n");
    fflush(stdout);
}

int main()
{
    int n; scanf("%d", &n);
    if (n % 2 == 0)
        solveFirst(n);
    else
        solveSecond(n);
    int res; scanf("%d", &res);
    return res;
}