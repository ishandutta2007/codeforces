#include<bits/stdc++.h>
#define maxn 200020

using namespace std;

int query,n,ans;

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        scanf("%d",&n);ans=0;
        if (n==11||n==7) printf("-1\n"); else{
            if (n%2==1) ans++,n-=9;
            ans+=n/4;
            if (ans>0) printf("%d\n",ans); else printf("-1\n");
        }
    }
    return 0;
}