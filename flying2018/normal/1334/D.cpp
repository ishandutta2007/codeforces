#include<iostream>
#include<cstdio>
#include<cstring>
#define N 500010
#define ll long long
using namespace std;
int arr[N],ar,pre[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;ll l;ll len;ar=0;
        scanf("%d%lld%lld",&n,&l,&len);len=len-l+1;
        int p=1;
        for(int i=1;i<=n;i++)
        {
            if(l<=2*(n-i)+1)
            {
                ar=0;
                for(int j=i+1;j<=n;j++) arr[++ar]=i,arr[++ar]=j;
                for(int i=l;i<=ar && len;i++) printf("%d ",arr[i]),len--;
                if(!len) break;
                l=1;
            }
            else l-=2*(n-i);
        }
        if(len) puts("1");
        else puts("");
    }
    return 0;
}