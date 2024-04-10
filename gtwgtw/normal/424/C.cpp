#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


int n,s[1000005],ans;


int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        ans^=x;
    }
    for(int i=1;i<=n;i++)s[i]=s[i-1]^i;
    for(int i=2;i<=n;i++)
    {
        int x=n/i,y=n%i;
        if(x&1)x=i-1;else x=0;
        ans^=s[x]^s[y];
    }
    printf("%d\n",ans);
    return 0;
}