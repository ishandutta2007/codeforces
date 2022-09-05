#include<bits/stdc++.h>

using namespace std;

int N;
char sir[10009];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d\n", &N);
scanf ("%s", sir + 1);
for (int i=1; i<=N; i++)
    sir[i] = (sir[i] == '*');
for (int r=1; r<=N; r++)
    for (int i=1; i<=r; i++)
    {
        int s = 0;
        for (int j=i; j<=N; j+=r)
            if (sir[j] == 0) s = 0;
            else
            {
                s ++;
                if (s == 5)
                {
                    printf ("yes\n");
                    return 0;
                }
            }
    }
printf ("no\n");

return 0;
}