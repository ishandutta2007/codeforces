#include<bits/stdc++.h>

using namespace std;

int N, K, X, ap[1030], nou[1030];

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d %d", &N, &K, &X);
for (int i=1; i<=N; i++)
{
    int val;
    scanf ("%d", &val), ap[val] ++;
}
while (K --)
{
    int bf = 0;
    memset (nou, 0, sizeof (nou));
    for (int i=0; i<1024; i++)
    {
        int oldAp = ap[i];
        if (ap[i] % 2 == 0) ap[i] /= 2, nou[i] += ap[i], nou[i ^ X] += ap[i];
        else
        {
            int ram, cu;
            if (bf % 2 == 0) cu = (ap[i] + 1) / 2;
            else cu = ap[i] / 2;
            ram = ap[i] - cu, nou[i] += ram, nou[i ^ X] += cu;
        }
        bf += oldAp;
    }
    memcpy (ap, nou, sizeof (nou));
/*    for (int i=0; i<1024; i++)
        for (int j=1; j<=nou[i]; j++)
            printf ("%d ", i);
    printf ("\n");*/
}
int mini = -1, maxi = -1;
for (int i=0; i<1024; i++)
    if (ap[i] > 0)
    {
        if (mini == -1) mini = i;
        maxi = i;
    }
printf ("%d %d\n", maxi, mini);
return 0;
}