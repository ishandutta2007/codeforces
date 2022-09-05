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

int N, K, A, B, Q, vec[200009], aib[4][200009];

void Update (int lin, int pos, int val)
{
    while (pos <= N) aib[lin][pos] += val, pos += pos - (pos & (pos - 1));
}

int Query (int lin, int pos)
{
    int sum = 0;
    while (pos) sum += aib[lin][pos], pos &= pos - 1;
    return sum;
}

void UnDo (int pos)
{
    if (vec[pos] <= B) Update (0, pos, -vec[pos]);
    else Update (1, pos, -1);
    if (vec[pos] <= A) Update (2, N - pos + 1, -vec[pos]);
    else Update (3, N - pos + 1, -1);
}

void Do (int pos)
{
    if (vec[pos] <= B) Update (0, pos, vec[pos]);
    else Update (1, pos, 1);
    if (vec[pos] <= A) Update (2, N - pos + 1, vec[pos]);
    else Update (3, N - pos + 1, 1);
}

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d %d %d", &N, &K, &A, &B, &Q);
while (Q --)
{
    int type;
    scanf ("%d", &type);
    if (type == 1)
    {
        int pos, cnt;
        scanf ("%d %d", &pos, &cnt);
        UnDo (pos), vec[pos] += cnt, Do (pos);
        continue;
    }
    int st, dr;
    scanf ("%d", &st), dr = st + K, st --;
    int ans = Query (0, st) + B * Query (1, st) +
                    Query (2, N - dr + 1) + A * Query (3, N - dr + 1);
    printf ("%d\n", ans);
}

return 0;
}