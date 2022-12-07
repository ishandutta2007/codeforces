#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[200005],GCD[200005][21];
bool F[200005];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++)
    {
        GCD[i][0]=a[i];
        for(int j=1;j<=20;j++)
        {
            if(i>=(1<<(j-1))) GCD[i][j]=__gcd(GCD[i][j-1],GCD[i-(1<<(j-1))][j-1]);
            else GCD[i][j]=GCD[i][j-1];
        }
    }
    int Lst=0;
    for(int i=1;i<=n;i++)
    {
        int tmpGCD=0,Now=i;
        for(int j=20;j>=0;j--)
        {
            if(__gcd(tmpGCD,GCD[Now][j]) >= (i - Now + (1<<j)))
            {
                tmpGCD=__gcd(tmpGCD,GCD[Now][j]);
                Now=max(Now-(1<<j),0);
            }
        }
        if(tmpGCD==i-Now && Now>=Lst)
        {
            Lst=i;
            F[i]=true;
        } 
    }
    int tmp=0;
    for(int i=1;i<=n;i++)
    {
        if(F[i]) tmp++;
        printf("%d ",tmp);
    }
    printf("\n");
}