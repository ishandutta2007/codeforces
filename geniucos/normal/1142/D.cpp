#include<bits/stdc++.h>

using namespace std;

int N, nxt[20][20];
long long cnt[20], old[20];
char sir[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

for (int i=0; i<11; i++)
    for (int j=0; j<11; j++)
        nxt[i][j] = -1;
int s = 9;
for (int i=1; i<=11; i++)
    for (int d = 0; d < i % 11; d ++)
        s ++,
        nxt[i % 11][d] = s % 11;
scanf ("%s", sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
    sir[i] -= '0';
long long ans = 0;
for (int i=1; i<=N; i++)
{
    for (int j=0; j<11; j++)
        old[j] = cnt[j], cnt[j] = 0;
    int d = sir[i];
    for (int j=0; j<11; j++)
        if (old[j] > 0 && nxt[j][d] != -1)
            cnt[nxt[j][d]] += old[j];
    if (d != 0)
        cnt[d] ++;
    for (int j=0; j<11; j++)
        ans += cnt[j];
}
printf ("%I64d\n", ans);
return 0;
}