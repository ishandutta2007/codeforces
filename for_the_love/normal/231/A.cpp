#include <cstdio>
#include <cstring>
int main()
{
        int n,ans,x,y,z;
        scanf("%d",&n);
        ans=0;
        while (n--)
        {
                scanf("%d%d%d",&x,&y,&z);
                x+=y+z;
                if (x>1) ans++;
        }
        printf("%d\n",ans);
}