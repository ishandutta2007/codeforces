#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[100001],mp[100001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i]);
            mp[a[i]]=i;
        }
        int lst=n+1;
        for(register int i=n;i>=1;--i)
        {
            if(lst==1)
                break;
            if(mp[i]>=lst)
                continue;
            for(register int j=mp[i];j<lst;++j)
                printf("%d ",a[j]);
            lst=mp[i];
        }
        puts("");
    }
    return 0;
}