#include<bits/stdc++.h>
using namespace std;
const int N=1E5+10;
int a[N],b[N];
int main()
{
    int x,s=0;
    long long ans=0;
    scanf("%d",&x);
    for(int j=x;j--;)
    {
        int n,l,k=0;
        scanf("%d%d",&n,&l);
        a[s]=b[s]=l;
        while(--n)
        {
            scanf("%d",b+s);
            if(b[s]>l)k=1;
            l=b[s];
        }
        k?++ans:++s;
    }
    sort(b,b+s),ans=ans*(x*2-ans);
    for(int i=0;i<s;++i)ans+=lower_bound(b,b+s,a[i])-b;
    printf("%lld",ans);
    return 0;
}