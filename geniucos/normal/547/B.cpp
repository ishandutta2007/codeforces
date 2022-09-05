#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

int N, nr, st[200009], L[200009], R[200009], A[200009], dp[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &A[i]);

nr = 0;
for (int i=1; i<=N; i++)
{
    while (nr && A[st[nr]] >= A[i])
        nr --;
    if (nr == 0)
        L[i] = 0;
    else
        L[i] = st[nr];
    st[++nr] = i;
}

nr = 0;
for (int i=N; i>=1; i--)
{
    while (nr && A[st[nr]] >= A[i])
        nr --;
    if (nr == 0)
        R[i] = N + 1;
    else
        R[i] = st[nr];
    st[++nr] = i;
}

for (int i=1; i<=N; i++)
    dp[R[i] - L[i] - 1] = max (dp[R[i] - L[i] - 1], A[i]);

for (int i=N; i>=1; i--)
    dp[i] = max (dp[i], dp[i+1]);

for (int i=1; i<=N; i++)
    printf ("%d ", dp[i]);
printf ("\n");

return 0;
}