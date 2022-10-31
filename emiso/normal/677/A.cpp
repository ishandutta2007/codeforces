#include <bits/stdc++.h>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int main()
{
    int n,k,h,ans;
    scanf("%d %d",&n,&h);
    ans = n;
    for(int i=0;i<n;i++) {
        scanf("%d",&k);
        if(k > h) ans++;
    }
    printf("%d\n",ans);
    return 0;
}