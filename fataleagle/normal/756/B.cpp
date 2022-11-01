#include <bits/stdc++.h>

using namespace std;

int N;
int A[100001];
int dp[100001];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i);
    for(int i=1; i<=N; i++)
    {
        dp[i]=dp[i-1]+20;
        int lo=1, mid, hi=i;
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            if(A[i]-A[mid]<90)
                hi=mid;
            else
                lo=mid+1;
        }
        dp[i]=min(dp[i], dp[lo-1]+50);
        lo=1, mid, hi=i;
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            if(A[i]-A[mid]<1440)
                hi=mid;
            else
                lo=mid+1;
        }
        dp[i]=min(dp[i], dp[lo-1]+120);
        printf("%d\n", dp[i]-dp[i-1]);
    }
    return 0;
}