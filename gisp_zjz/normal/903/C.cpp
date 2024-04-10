#include<bits/stdc++.h>
#define maxn 100000

using namespace std;

int n,a[maxn],cnt,ans;

int main()
{
    scanf("%d",&n); for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n); ans=1; cnt=1;
    for (int i=1;i<n;i++)
    {
        if (a[i]==a[i-1]) cnt++; else cnt=1;
        ans=max(cnt,ans);
    }
    printf("%d\n",ans);return 0;
}