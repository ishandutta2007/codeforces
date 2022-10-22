#include<cstdio>
#include<map>
using namespace std;
map<int,bool> mp;
int t,n,a[105],ans;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        mp.clear();
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(!mp[a[i]-a[j]])
                {
                    mp[a[i]-a[j]]=1;
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
}