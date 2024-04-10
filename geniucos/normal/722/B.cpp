#include<bits/stdc++.h>

using namespace std;

int N, a[109];
char sir[109];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%d", &a[i]);
scanf ("\n");
for (int i=1; i<=N; i++)
{
    int curr = 0, M;
    gets (sir + 1), M = strlen (sir + 1);
    for (int j=1; j<=M; j++)
        curr += (sir[j] == 'a' || sir[j] == 'e' || sir[j] == 'i' || sir[j] == 'y' || sir[j] == 'o' || sir[j] == 'u');
    if (curr != a[i])
    {
        printf ("NO\n");
        return 0;
    }
}
printf ("YES\n");
return 0;
}