#include<cstdio>
#include<map>
using namespace std;
int n,k,t;
int a[100005],ans[100005];
map<int,int> mp;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int cur = 0;
        for(int i=n;i>=1;i--)
        {
            if(a[i] <= cur) 
            {
                ans[i] = 1;
            }
            else if(cur < k)
            {
                ans[i] = 1;
                cur++;
            }
            else ans[i] = 0;
        }
        for(int i=1;i<=n;i++) printf("%d",ans[i]);
        printf("\n");
    }
}