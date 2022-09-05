#include<bits/stdc++.h>

using namespace std;

int N, W, real_ans[1009], ans[1009];
pair < int, int > v[1009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &W);
for (int i=1; i<=N; i++)
    scanf ("%d", &v[i].first), v[i].second = i;
sort (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
    ans[i] = (v[i].first + 1) / 2, W -= ans[i];
if (W < 0)
{
    printf ("-1\n");
    return 0;
}
while (W --)
{
    for (int i=N; i>=1; i--)
        if (ans[i] < v[i].first)
        {
            ans[i] ++;
            break;
        }
}
for (int i=1; i<=N; i++)
    real_ans[v[i].second] = ans[i];
for (int i=1; i<=N; i++)
    printf ("%d%c", real_ans[i], " \n"[i == N]);
return 0;
}