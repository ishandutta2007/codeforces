#include<cstdio>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<map>
#include<set>
#include<queue>
#include<algorithm>

using namespace std;

int N;
double P[1009];

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d", &N);
for (int i=1; i<=N; i++)
    scanf ("%lf", &P[i]);
sort (P + 1, P + N + 1);
double maxi = P[N];
for (int j=1; j<=N; j++)
{
    double A = 1.0, B = 0.0;
    for (int i=j; i<=N; i++)
    {
        double curr = (double) P[i] / (1.0 - P[i]);
        B += curr;
        A *= (double) (1.0 - P[i]);
        if (A * B > maxi)
            maxi = A * B;
    }
}
printf ("%.10lf\n", maxi);
return 0;
}