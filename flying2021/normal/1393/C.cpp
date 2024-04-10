#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define N 100010
using namespace std;
int a[N],cnt[N],res[N],n;
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
        sort(cnt+1,cnt+n+1,greater<int>());
        int m=cnt[1];
        cnt[1]--;
        for(int i=2;i<=n;i++)
        if(cnt[i]>cnt[i-1]) cnt[i]--;
        else break;
        --m;
        int p=1;
        for(int i=1;cnt[i];i++)
        {
            for(int j=1;j<=cnt[i];j++,p=p%m+1) res[p]++;
        }
        int ans=100000000;
        for(int i=1;i<=m;i++)
        {
            if(res[i]<ans) ans=res[i];
        }
        printf("%d\n",ans-1);
        for(int i=1;i<=n;i++) res[i]=cnt[i]=0;
    }
}