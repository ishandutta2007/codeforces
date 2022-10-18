#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int t,n,minn,p;
struct node
{
    int num,id;
    bool operator <(const node &other) const
    {
        return num<other.num;
    }
}a[100001];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        minn=1<<30,p=0;
        for(register int i=1;i<=n;++i)
        {
            scanf("%d",&a[i].num);
            a[i].id=i;
        }
        sort(a+1,a+n+1);
        for(register int i=1;i<=n;++i)
            if(a[i].num<minn)
            {
                minn=a[i].num;
                p=i;
            }
        bool flag=1;
        for(register int i=1;i<=n;++i)
            if(a[i].id!=i&&a[a[i].id].num!=a[i].num)
                if(a[i].num%minn)
                {
                    puts("NO");
                    flag=0;
                    break;
                }
        if(flag)
            puts("YES");
    }
    return 0;
}