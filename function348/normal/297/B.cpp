#include<cstdio>
#include<algorithm>
int main()
{
    int n,m,k;
    int a[100010],b[100010];
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);std::sort(a+1,a+1+n);
    for (int i=1;i<=m;i++) scanf("%d",&b[i]);std::sort(b+1,b+1+m);
    int ok=0;
    for (int i=n,j=m;i>=1||j>=1;)
    {
        if (a[i]<b[j])
        {
            j--;
            while (b[j]==b[j+1]) j--;
        }
        else
        if (a[i]>b[j])
        {
            i--;
            while (a[i]==a[i+1]) i--;
        }
        else i--,j--;
        if (n-i>m-j) {ok=1;break;}
    }
    printf(ok?"YES":"NO");
    return 0;
}