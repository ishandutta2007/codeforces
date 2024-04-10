#include<cstdio>
using namespace std;

int n,k,t;
int Plus(int x,int y)
{
    int ans=0,_Base=1,Base=k;
    while(x>=_Base || y>=_Base)
    {
        ans+=((((x%Base)/_Base)+((y%Base)/_Base))%k)*_Base;
        Base*=k;
        _Base*=k;
    }
    return ans;
}
int Minus(int x,int y)
{
    int ans=0,_Base=1,Base=k;
    while(x>=_Base || y>=_Base)
    {
        ans+=((((x%Base)/_Base)-((y%Base)/_Base)+k)%k)*_Base;
        Base*=k;
        _Base*=k;
    }
    return ans;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        int Now=0;
        bool flag=0;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            if(i%2==1) printf("%d\n",Minus(Now,i));
            if(i%2==0) printf("%d\n",Plus(Now,i));
            fflush(stdout);
            scanf("%d",&flag);
            if(flag==1) break;
            if(i%2==1) Now=Minus(0,i);
            if(i%2==0) Now=i;
        }
    }
}