#include<bits/stdc++.h>

using namespace std;

int N, M, ans;
char sir[109];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d\n", &N, &M);
while (N --) gets (sir + 1);
for (int i=1; i<=M; i++)
    if (sir[i] == 'B')
    {
        int j = i;
        while (sir[j] == 'B' && j<=M) j ++;
        ans ++, i = j;
    }
printf ("%d\n", ans);

return 0;
}