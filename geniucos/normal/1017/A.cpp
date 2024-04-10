#include<bits/stdc++.h>

using namespace std;

int N;
pair < int, int > v[1009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
{
    int x = 0, y;
    for (int j=0; j<4; j++)
        scanf ("%d", &y), x += y;
    v[i].first = -x, v[i].second = i;
}
sort (v + 1, v + N + 1);
for (int i=1; i<=N; i++)
    if (v[i].second == 1)
    {
        printf ("%d\n", i);
        break;
    }

return 0;
}