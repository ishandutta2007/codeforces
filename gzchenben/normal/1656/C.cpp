#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        bool flag=false;
        for(int i=1;i<=n;i++) if(a[i]==1) flag=true;
        if(!flag)
        {
            printf("YES\n");
            continue;
        }
        if(a[1]==0) 
        {
            printf("NO\n");
            continue;
        }
        flag=false;
        for(int i=2;i<=n;i++)
        {
            if(a[i]==a[i-1]+1) flag=true;
        }
        printf(flag ? "NO\n" : "YES\n");
    }
}