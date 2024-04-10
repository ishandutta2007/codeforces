#include<bits/stdc++.h>

using namespace std;

int sg, knt, N, M, frq[300], dp[100009];
char sir[100009];
bool ap[100009];

void solve (int st, int dr)
{
    if (dr - st + 1 < M) return;
//    printf ("[%d, %d]\n", st, dr);
    deque < int > dq;
    int mini = N + 3;
    for (int i=st; i<=dr; i++)
    {
        dp[i] = N + 3;
        if (sir[i] == sg)
        {
            if (i - st < M) dp[i] = 1;
            else dp[i] = 1 + dp[dq.front ()];
        }
        while (!dq.empty () && dp[dq.back ()] >= dp[i]) dq.pop_back ();
        dq.push_back (i);
        if (dq.front () <= i - M) dq.pop_front ();
        if (dr - i < M && dp[i] < mini) mini = dp[i];
    }
    knt += mini;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &M);
gets (sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
    sir[i] -= 'a', frq[sir[i]] ++;
for (int i=0; i<26; i++)
{
    for (int j=1; j<=N; j++)
        ap[j] = (sir[j] <= i);
    int lst = 0;
    bool ok = 1;
    for (int j=1; j<=N; j++)
    {
        if (j - lst - 1 >= M) ok = 0;
        if (ap[j]) lst = j;
    }
    if (N - lst >= M) ok = 0;
    if (ok)
    {
        sg = i;
        break;
    }
}
knt = 0;
for (int i=0; i<sg; i++)
    for (int j=0; j<frq[i]; j++)
        printf ("%c", 'a' + i);
for (int i=1; i<=N; i++)
    if (sir[i] >= sg)
    {
        int j = i;
        for (j = i; j<=N; j++)
            if (sir[j] < sg) break;
        j --;
        ///solve [i, j]
        solve (i, j);
        ///
        i = j;
    }
while (knt --) printf ("%c", 'a' + sg);
printf ("\n");
return 0;
}