#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
typedef long long LL;
typedef pair<int,int> PII;
const double eps=1e-8;
const double pi=acos(-1.0);
const int K=1e6+7;
const int mod=1e9+7;

int n,a[K],b[K],cnt,ans[K],sa[K],sb[K];

int main(void)
{
    ans[0]=-1;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("? %d %d\n",i,0);
        fflush(stdout);
        scanf("%d",a+i);
    }
    for(int i=0;i<n;i++)
    {
        printf("? %d %d\n",0,i);
        fflush(stdout);
        scanf("%d",b+i);
    }
    for(int i=0;i<n;i++)
    {
        int ff=1;
        for(int j=0;j<n;j++)
            sa[j]=i^a[j];
        for(int j=0;j<n;j++)
            sb[j]=sa[0]^b[j];
        for(int j=0;j<n&&ff;j++)
        if(sa[sb[j]]!=j)
            ff=0;
        cnt+=ff;
        if(ans[0]==-1&&ff)
        {
            for(int j=0;j<n;j++)
                ans[j]=sa[j];
        }
    }
    printf("!\n%d\n",cnt);
    for(int i=0;i<n;i++)
        printf("%d ",ans[i]);
    fflush(stdout);
    return 0;
}