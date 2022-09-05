#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int nr, N, maxi, a[109], ap[109], Ap[109], ans[109];
long long M;

void solve (int st, int dr, long long val)
{
    if (st == dr)
    {
        ans[st] = 1;
        return;
    }
    if (val <= (1LL << (dr-st-1)))
    {
        ans[st] = 1;
        solve (st + 1, dr, val);
        for (int i=st+1;i<=dr;i++)
            ans[i] ++;
        return;
    }
    solve (st, dr-1, (long long)val - (1LL << (dr-st-1)));
    ans[dr] = 1;
    for (int i=st; i<dr;i++)
        ans[i]++;
}

void calc (long long nr)
{
    solve (1, N, nr);
    for (int i=1; i<=N; i++)
        printf ("%d ", ans[i]);
    printf ("\n");
}


int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %I64d", &N, &M);

calc (M);

return 0;
}