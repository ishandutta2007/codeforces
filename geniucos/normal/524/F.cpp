#include<bits/stdc++.h>

using namespace std;

int ans, mini, N, lg, dp[22][1000009], s[2000009], pos[1000009];
char sir[2000009];
pair < pair < int, int >, int > A[2000009];
deque < int > dq;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1), ans = -1;
for (int i=N + 1; i<=2 * N; i++)
    sir[i] = sir[i - N];
for (int i=1; i<=2 * N; i++)
{
    s[i] = s[i - 1];
    if (sir[i] == '(') s[i] ++;
    else s[i] --;
    if (s[i] < mini && i < N) mini = s[i];
}
for (int i=1; i<=N; i++)
    dp[0][i] = sir[i], A[i] = make_pair (make_pair (0, 0), i);
for (int i=1; (1<<(i - 1)) <= N; i++)
{
    int P = (1 << (i - 1));
    for (int j=1; j<=N; j++)
    {
        int k = A[j].second;
        A[j].first.first = dp[i - 1][k];
        if (k + P <= N) A[j].first.second = dp[i - 1][k + P];
        else A[j].first.second = dp[i - 1][k + P - N];
    }
    sort (A + 1, A + N + 1);
    for (int j=1; j<=N; j++)
        dp[i][A[j].second] = dp[i][A[j - 1].second] + (j == 1 || A[j].first != A[j - 1].first);
}
for (int i=1; i<=N; i++)
    pos[A[i].second] = i;
int Konst = 0;
if (s[N] < 0) Konst = s[N];
int j = 0;
for (int i=0; i<N; i++)
{
    while (j <= i + N)
    {
        while (!dq.empty () && s[dq.back ()] >= s[j]) dq.pop_back ();
        dq.push_back (j);
        while (dq.front () <= j - N) dq.pop_front ();
        j ++;
    }
    ///s[j] - s[i] >= Konst pentru orice j de la i + 1 la i + N
    if (s[dq.front ()] - s[i] >= Konst)
    {
        //printf ("%d\n", i + 1);
        if (ans == -1) ans = i + 1;
        else
        {
            ///trebuie sa compar doua sufixe:
            if (pos[i + 1] < pos[ans]) ans = i + 1;
        }
    }
}
while (s[N] < 0) printf ("("), s[N] ++;
for (int i=ans; i<=N + ans - 1; i++)
    printf ("%c", sir[i]);
while (s[N] > 0) printf (")"), s[N] --;
printf ("\n");
return 0;
}