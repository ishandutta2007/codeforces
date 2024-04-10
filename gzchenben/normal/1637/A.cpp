#include<cstdio>
using namespace std;
int n,t,a[100005];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        bool flag=true;
        for(int i=1;i<n;i++) if(a[i]>a[i+1]) flag=false;
        printf(flag ? "NO\n" : "YES\n");
    }
}