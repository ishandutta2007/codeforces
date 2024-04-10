#include<cstdio>
#include<bitset>
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

int N, M, K, pos[20], dp[10][10][800009], left[800009], right[800009], lazy[800009];
char sir[200009], order[20];

void Build (int nod, int st, int dr)
{
    if (st == dr)
    {
        left[nod] = right[nod] = sir[st] - 'a';
        return ;
    }
    int mij = (st + dr) >> 1;
    Build (nod << 1, st, mij);
    Build ((nod << 1) + 1, mij + 1, dr);
    for (int i=0; i<K; i++)
        for (int j=0; j<K; j++)
            dp[i][j][nod] = dp[i][j][nod << 1] + dp[i][j][(nod << 1) + 1];
    dp[right[nod << 1]][left[(nod << 1) + 1]][nod] ++;
    right[nod] = right[(nod << 1) + 1];
    left[nod] = left[nod << 1];
}

void Fix (int nod, int st, int dr, int val)
{
    for (int i=0; i<K; i++)
        for (int j=0; j<K; j++)
            dp[i][j][nod] = 0;
    dp[val][val][nod] += dr - st;
    lazy[nod] = val + 1;
    left[nod] = right[nod] = val;
}

void split (int nod, int st, int mij, int dr)
{
    if (lazy[nod] > 0)
    {
        int val = lazy[nod] - 1;
        Fix (nod << 1, st, mij, val);
        Fix ((nod << 1) + 1, mij + 1, dr, val);
        lazy[nod] = 0;
    }
}

void Print (int nod)
{
    printf ("%d:\n", nod);
    for (int i=0; i<K; i++, printf ("\n"))
        for (int j=0; j<K; j++)
            printf ("%d", dp[i][j][nod]);
    printf ("\n\n");
}

void Update (int nod, int st, int dr, int x, int y, int val)
{
    if (x <= st && dr <= y)
    {
        Fix (nod, st, dr, val);
        return ;
    }
    int mij = (st + dr) >> 1;
    split (nod, st, mij, dr);
    if (x <= mij) Update (nod << 1, st, mij, x, y, val);
    if (y > mij) Update ((nod << 1) + 1, mij + 1, dr, x, y, val);
    for (int i=0; i<K; i++)
        for (int j=0; j<K; j++)
            dp[i][j][nod] = dp[i][j][nod << 1] + dp[i][j][(nod << 1) + 1];
    dp[right[nod << 1]][left[(nod << 1) + 1]][nod] ++;
    right[nod] = right[(nod << 1) + 1];
    left[nod] = left[nod << 1];
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d\n", &N, &M, &K);
gets (sir + 1);
Build (1, 1, N);
while (M --)
{
    int type;
    scanf ("%d ", &type);
    if (type == 1)
    {
        int st, dr;
        char c;
        scanf ("%d %d %c\n", &st, &dr, &c);
        Update (1, 1, N, st, dr, c - 'a');
        continue;
    }
    gets (order + 1);
    for (int i=1; i<=K; i++)
        pos[order[i] - 'a'] = i;

    int curr = 0;
    for (int i=0; i<K; i++)
        for (int j=0; j<K; j++)
            if (pos[j] > pos[i]) curr += dp[i][j][1];
    printf ("%d\n", N - curr);
}

return 0;
}