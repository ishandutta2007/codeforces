#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int i,j,n,mini,l,a[150009],s[150009];
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
int det(int x1,int y1,int x2,int y2,int x3,int y3)
{
    return mod(x1*y2+x2*y3+x3*y1-x1*y3-x2*y1-x3*y2);
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&l);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    s[i]=s[i-1]+a[i];
}
mini=1000000000;
for(i=l;i<=n;i++)
    if(s[i]-s[i-l]<mini)
    {
        mini=s[i]-s[i-l];
        j=i-l+1;
    }
printf("%d\n",j);
return 0;
}