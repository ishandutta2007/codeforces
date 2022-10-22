#include<cstdio>
using namespace std;
int n,k,t,a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        bool flag0=false,flag1=false;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i] == 1) flag1=true;
        }
            printf(flag1 ? "YES\n" : "NO\n");
    }
}