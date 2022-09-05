#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int i,n,a[309];
int mod(int a)
{
    if(a<0) return -a;
    return a;
}
int min(int a,int b)
{
    if(a<b) return a;
    return b;
}
int max(int a,int b)
{
    if(a>b) return a;
    return b;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
for(i=1;i<n;i++)
{
    while(a[i])
    {
        a[i]--;
        printf("PRL");
    }
    printf("R");
}
while(a[n])
{
    a[n]--;
    printf("PLR");
}
printf("\n");
return 0;
}