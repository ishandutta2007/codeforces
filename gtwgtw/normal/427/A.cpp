#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n,x,hire,ans;


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(x>0)hire+=x;
        if(x<0)
        {
            if(hire)hire--;
            else    ans++;
        }
    }
    printf("%d\n",ans);
    return 0;
}