#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,t,a[100005],b[100005];
bool cmp(int x,int y)
{
    return x>y;
}
bool check(int x)
{
    int C=x-x/4;
    int Ans1=0,Ans2=0;
    for(int i=x-C+1;i<=x;i++)
    {
        if(i>n) Ans1+=100;
        else Ans1+=a[i];
    }
    for(int i=1;i<=C;i++)
    {
        if(i<=n) Ans2+=b[i];
    }
    return Ans1<Ans2;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&b[i]);
        }
        sort(b+1,b+n+1,cmp);
        int L=0,R=n+1;
        while(L<R)
        {
            int mid=(L+R)/2;
            if(check(n+mid)) L=mid+1;
            else R=mid;
        }
        printf("%d\n",L);
    }
}