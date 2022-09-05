#include<iomanip>
#include<iostream>
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

int N, M, A[509];
double maxi;

int main()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
for (int i=1; i<=N; i++)
    scanf ("%d", &A[i]);
for (int i=1; i<=M; i++)
{
    int x, y, c;
    scanf ("%d %d %d", &x, &y, &c);
    double curr = (double) (A[x] + A[y]) / c;
    if (curr > maxi)
        maxi = curr;
}
printf ("%.10lf\n", maxi);

return 0;
}