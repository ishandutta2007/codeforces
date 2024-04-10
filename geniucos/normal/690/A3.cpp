#include<bits/stdc++.h>

using namespace std;

int T, N, S, pos;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &T);
while (T --)
{
    scanf ("%d %d", &N, &pos), pos --, S = 0;
    for (int i=1; i<N; i++)
    {
        int val;
        scanf ("%d", &val), val --;
        if ((S += val) >= N) S -= N;
    }
    if ((pos -= S) < 0) pos += N;
    printf ("%d\n", pos + 1);
}

return 0;
}