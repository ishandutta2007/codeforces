#include<bits/stdc++.h>

using namespace std;

int N;
char sir[10009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1);
int allEq = 1;
for (int i=2; i<=N; i++)
{
    if (i == (N + 1) / 2 && N % 2 == 1) continue;
    if (sir[i] != sir[1])
        allEq = 0;
}
if (allEq)
{
    printf ("Impossible\n");
    return 0;
}
for (int i=N + 1; i<=2 * N; i++)
    sir[i] = sir[i - N];
for (int i=2; i<=N; i++)
{
    bool ok = 0;
    for (int j=1; j<=N; j++)
        if (sir[j] != sir[i + j - 1])
        {
            ok = 1;
            break;
        }
    if (!ok) continue;
    for (int j=1; j<=N; j++)
        if (sir[i + j - 1] != sir[i + N - j])
        {
            ok = 0;
            break;
        }
    if (ok)
    {
        printf ("1\n");
        return 0;
    }
}
printf ("2\n");
return 0;
}