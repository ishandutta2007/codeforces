#include<bits/stdc++.h>

using namespace std;

int N, a[30], ans[30];
pair < int, int > b[30];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=0; i<N; i++)
    scanf ("%d", &a[i]), b[i] = {a[i], i};
sort (b, b + N);
for (int i=0; i<N; i++)
    ans[b[i].second] = b[(i + 1) % N].first;
for (int i=0; i<N; i++)
    printf ("%d ", ans[i]);
printf ("\n");
return 0;
}