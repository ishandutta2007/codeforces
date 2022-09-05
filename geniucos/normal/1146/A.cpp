#include<bits/stdc++.h>

using namespace std;

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

char sir[100];
int N, a = 0;
scanf ("%s", sir + 1), N = strlen (sir + 1);
for (int i=1; i<=N; i++)
    a += (sir[i] == 'a');
printf ("%d\n", min (N, 2 * a - 1));
return 0;
}