#include <bits/stdc++.h>
using namespace std;
#define long long ll
int main()
{
    int l=1,r=1e9;
    int dp[200008];
    int n,k; scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++) scanf("%d",&dp[i]);
    while(l<=r)
    {
        int mid=(l+r)/2,cnt=0;
        for(int j=0;j<n;j++)
        {
            if(mid>=dp[j]) cnt++;
        }
        if(cnt==k) return !printf("%d",mid);
        if(cnt<k) l=mid+1;
        else r=mid-1;
    }
    return !printf("-1");
}