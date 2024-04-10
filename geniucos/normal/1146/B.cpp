#include<bits/stdc++.h>

using namespace std;

int cnt, N, M;
char sir[200009], ans[200009];

void fail ()
{
    printf (":(\n");
    exit (0);
}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", sir + 1), M = strlen (sir + 1);
for (int i=1; i<=M; i++)
    cnt += (sir[i] != 'a');
if (cnt & 1) fail ();
N = M - cnt / 2;
for (int i=1; i<=N; i++)
    ans[i] = sir[i];
int nr = N;
for (int i=1; i<=N; i++)
    if (ans[i] != 'a')
        ans[++nr] = ans[i];
for (int i=1; i<=M; i++)
    if (ans[i] != sir[i])
        fail ();
for (int i=1; i<=N; i++)
    printf ("%c", ans[i]);
printf ("\n");
return 0;
}