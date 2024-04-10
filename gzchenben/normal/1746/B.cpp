#include<cstdio>
using namespace std;
int n,t,a[100005];
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
        int L = 1,R = n,ans = 0;
        while(L < R)
        {
            while(a[L] == 0 && L < R) L++;
            while(a[R] == 1 && L < R) R--;
            if(L < R)
            {
                ans++;
                L++;
                R--;
            }
        }
        printf("%d\n",ans);
    }
}