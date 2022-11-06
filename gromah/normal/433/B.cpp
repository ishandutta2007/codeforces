#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 100000 + 5;
int n, A[N];
LL sumA[N], sumB[N];
void begin()
{
//    freopen("B.in", "r", stdin);
//    freopen("B.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++)
        scanf("%d", A + i), sumA[i] = sumA[i - 1] + A[i];
    sort(A + 1, A + n + 1);
    for (int i = 1; i <= n; i ++)
        sumB[i] = sumB[i - 1] + A[i];
}
void work()
{
    int q;
    scanf("%d", &q);
    while (q --)
    {
        int t, u, v;
        LL ans = 0;
        scanf("%d%d%d", &t, &u, &v);
        if (t == 1) ans = sumA[v] - sumA[u - 1];
            else ans = sumB[v] - sumB[u - 1];
        cout << ans << endl;
    }
}
void end()
{
//    fclose(stdin);
//    fclose(stdout);
}
int main()
{
    begin();
    work();
    end();
    return 0;
}