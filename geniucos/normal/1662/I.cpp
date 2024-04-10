#include<bits/stdc++.h>

using namespace std;

const int maxN = 200009;
int N, M, p[maxN], x[maxN], lft[maxN], d[maxN], pos[maxN];

bool ok(int i, int j) {
    if (i > j)
        return 1;
    if (lft[j] > 0 && x[lft[j]] >= pos[i])
        return 0;
    ///there's no ice cream shop between pos[i] and pos[j]
    if (lft[j] == 0)
        return 1;
    if (lft[i] == M)
        return 1;
    assert(lft[i] == lft[j]);
    return (2 * pos[j] - x[lft[i] + 1] < 2 * pos[i] - x[lft[i]]);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

int tests = 1;
//scanf ("%d", &tests);
while (tests --)
{
    scanf ("%d %d", &N, &M);
    for (int i=1; i<=N; i++)
        scanf ("%d", &p[i]),
        pos[i] = 100 * (i - 1);
    for (int i=1; i<=M; i++)
        scanf ("%d", &x[i]);
    sort(x + 1, x + M + 1);
    int j = 0;
    for (int i=1; i<=N; i++) {
        while (j < M && x[j + 1] <= pos[i])
            j ++;
        lft[i] = j;
        if (j == 0) d[i] = x[1] - pos[i];
        else
        if (j == M) d[i] = pos[i] - x[j];
        else d[i] = min(pos[i] - x[j], x[j + 1] - pos[i]);
    }
    j = 0;
    long long ans = 0, currS = 0;
    for (int i=1; i<=N; i++) {
        while (j < N && ok(i, j + 1))
            j ++, currS += p[j];
        if (currS > ans)
            ans = currS;
        if (i <= j)
            currS -= p[i];
        else
            j = i, currS = 0;
    }
    printf("%I64d\n", ans);
}

return 0;
}

/*
const int seed = time (0);
mt19937 gen (seed);
long long getRand(long long a, long long b) {return uniform_int_distribution < long long > (a, b) (gen);}
*/