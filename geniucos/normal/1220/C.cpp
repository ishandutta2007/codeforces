#include<bits/stdc++.h>

using namespace std;

int N;
char sir[500009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%s", sir + 1), N = strlen (sir + 1);
int minSoFar = 10000;
for (int i=1; i<=N; i++)
{
    if (sir[i] > minSoFar) printf ("Ann\n");
    else printf ("Mike\n"), minSoFar = sir[i];
}
return 0;
}