#include<bits/stdc++.h>

using namespace std;

int N, cnt[109], type[200009];
long long x[200009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    scanf ("%I64d", &x[i]);
    for (int j=0; j<63; j++)
        if (x[i] & (1LL << j))
        {
            cnt[j] ++, type[i] = j;
            break;
        }
}
int ans = 0, how = -1;
for (int i=0; i<63; i++)
    if (cnt[i] > ans)
        ans = cnt[i], how = i;
printf ("%d\n", N - ans);
for (int i=1; i<=N; i++)
    if (type[i] != how)
        printf ("%I64d ", x[i]);
printf ("\n");
return 0;
}