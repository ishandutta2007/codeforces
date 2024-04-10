#include <bits/stdc++.h>

using namespace std;

int N;
double A[101];

double solve(int l, int r)
{
    double ret=0.0;
    double tmp=1.0;
    for(int i=l; i<=r; i++)
        tmp*=1.0-A[i];
    for(int i=l; i<=r; i++)
        ret+=A[i]*(tmp/(1.0-A[i]));
    return ret;
}

int main()
{
    scanf("%d", &N);
    double maxi=0.0;
    for(int i=0; i<N; i++)
    {
        scanf("%lf", A+i);
        maxi=max(maxi, A[i]);
    }
    if(maxi>=0.5)
        printf("%.18lf\n", maxi);
    else
    {
        sort(A, A+N);
        maxi=0.0;
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                maxi=max(maxi, solve(i, j));
        printf("%.18lf\n", maxi);
    }
    return 0;
}