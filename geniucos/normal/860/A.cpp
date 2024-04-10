#include<bits/stdc++.h>

using namespace std;

int N, ap[3009], dp[3009], how[3009];
char sir[3009];

bool cons (char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return 0;
    return 1;
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

gets (sir + 1), N = strlen (sir + 1);
dp[0] = 0;
for (int i=1; i<=N; i++)
{
    char mini = sir[i], maxi = sir[i];
    int L = cons (sir[i]);
    dp[i] = dp[i - 1] + 1, how[i] = i;
    for (int j=i - 1; j>=1; j--)
    {
        if (cons (sir[j]) == 0) L = 0;
        else
        {
            if (L == 0) mini = maxi = sir[j], L = 1;
            else L ++, mini = min (mini, sir[j]), maxi = max (maxi, sir[j]);
        }
        if (L >= 3 && mini < maxi)
            break;
        if (dp[j - 1] + 1 < dp[i])
            dp[i] = dp[j - 1] + 1, how[i] = j;
    }
}
int pos = N;
while (pos > 0)
    pos = how[pos] - 1, ap[pos] = 1;
for (int i=1; i<=N; i++)
{
    printf ("%c", sir[i]);
    if (ap[i]) printf (" ");
}
printf ("\n");
return 0;
}