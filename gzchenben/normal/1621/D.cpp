#include<cstdio>
#include<algorithm>
using namespace std;
int n,t,a[1000][1000];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        long long tot=0;
        for(int i=1;i<=2*n;i++)
        {
            for(int j=1;j<=2*n;j++)
            {
                scanf("%d",&a[i][j]);
                if(i>n && j>n) tot+=a[i][j];
            }
        }
        printf("%lld\n",tot+min(min(min(a[n+1][n],a[n][n+1]),min(a[2*n][1],a[1][2*n])),min(min(a[n][2*n],a[2*n][n]),min(a[n+1][1],a[1][n+1]))));
    }
}