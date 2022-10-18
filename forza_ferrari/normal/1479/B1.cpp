#include<iostream>
#include<cstdio>
using namespace std;
int n,a[100005],ans,lst1,lst2;
int main()
{
    scanf("%d",&n);
    for(register int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(register int i=1;i<=n;++i)
    {
        if((lst1^a[i])&&(lst2^a[i]))
        {
            if(lst1==a[i+1])
            {
                ++ans;
                lst1=a[i];
            }
            else
            {
                ++ans;
                lst2=a[i];
            }
        }
        else
            if(lst1^a[i])
            {
                ++ans;
                lst1=a[i];
            }
            else
                if(lst2^a[i])
                {
                    ++ans;
                    lst2=a[i];
                }
    }
    printf("%d\n",ans);
    return 0;
}