#include<bits/stdc++.h>

using namespace std;

int N;
char sir[100009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n%s", &N, sir + 1);
int z = 0, u = 0;
for (int i=1; i<=N; i++)
    if (sir[i] == 'n') u ++;
    else z += (sir[i] == 'z');
while (u --) printf ("1 ");
while (z --) printf ("0 ");
printf ("\n");
return 0;
}