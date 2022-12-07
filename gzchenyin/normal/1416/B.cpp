#include<cstdio>
using namespace std;
int n,t,a[10005],opt1[50005],opt2[50005],opt3[50005],top;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        top=0;
        scanf("%d",&n);
        long long sum=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum+=a[i];
        }
        if(sum%n!=0)
        {
            printf("-1\n");
            continue;
        }
        sum=sum/n;
        for(int i=2;i<=n;i++)
        {
            while(a[i]!=0)
            {
                if(a[i]%i==0)
                {
                    top++;
                    opt1[top]=i;
                    opt2[top]=1;
                    opt3[top]=a[i]/i;
                    a[1]+=opt3[top]*i;
                    a[i]-=opt3[top]*i;
                }
                else
                {
                    top++;
                    opt1[top]=1;
                    opt2[top]=i;
                    opt3[top]=i-(a[i]%i);
                    a[1]-=i-(a[i]%i);
                    a[i]+=i-(a[i]%i);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            top++;
            opt1[top]=1;
            opt2[top]=i;
            opt3[top]=sum;
        }
        printf("%d\n",top);
        for(int i=1;i<=top;i++)
        {
            printf("%d %d %d\n",opt1[i],opt2[i],opt3[i]);
        }
    }
    
}