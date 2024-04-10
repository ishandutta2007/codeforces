#include<bits/stdc++.h>
using namespace std;

int n;
long long int arr[300001];
long long int dp[300001];
long long int remain[300001];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%lld", &arr[i]);

    for(int i=1; i<=n; i++)
    {
        long long k = min(remain[i-1], arr[i]/2);
        long long r=dp[i-1];

        r+=k;
        r+=(arr[i]-2*k)/3;

        remain[i]=(remain[i-1]-k) + (arr[i]-2*k)%3;
        dp[i]=r;
    }

    printf("%lld", dp[n]);
}