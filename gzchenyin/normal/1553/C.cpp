#include<cstdio>
using namespace std;
int n,Remain[2],Maxdif[2];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        Remain[0]=Remain[1]=5;
        Maxdif[0]=Maxdif[1]=0;
        int ans=10;
        for(int j=1;j<=10;j++)
        {
            char tmp;
            scanf(" %c",&tmp);
            Remain[j%2]--;
            if(tmp=='1')
            {
                Maxdif[j%2]++;
                Maxdif[1-(j%2)]--;
            }
            if(tmp=='?')
            {
                Maxdif[j%2]++;
            }
            if(ans!=10) continue;
            if(Maxdif[1]>Remain[0] || Maxdif[0]>Remain[1])
            {
                ans=j;
            }
        }
        printf("%d\n",ans);
    }
}