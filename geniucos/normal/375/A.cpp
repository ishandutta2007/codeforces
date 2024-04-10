#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int p,m,i,j,ap[300],a[10];
int v[]={689,698,869,896,986,968};
char sir[1000009];
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
gets(sir+1);
m=strlen(sir+1);
for(i=1;i<=m;i++)
    ap[sir[i]-'0']++;
for(i=0;i<6;i++)
    a[v[i]%7]=v[i];
ap[1]--;
ap[6]--;
ap[8]--;
ap[9]--;
for(i=1;i<=9;i++)
    for(j=1;j<=ap[i];j++)
    {
        printf("%d",i);
        p=(p*10+i)%7;
    }
if(p==1) printf("6891");
else printf("1%d",a[(p*10+1)%7]);
for(i=1;i<=ap[0];i++)
    printf("0");
printf("\n");
return 0;
}