#include<cstdio>
#include<cstring>
using namespace std;
int s,t,n,i,ap[5],pr[5],a[1009];
char sir[1009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d\n",&n);
gets(sir+1);
for(i=1;i<=n;i++)
{
    if(sir[i]=='.') a[i]=0;
    else
    if(sir[i]=='L') a[i]=1;
    else a[i]=2;
    ap[a[i]]++;
    if(ap[a[i]]==1) pr[a[i]]=i;
}
if(ap[1]+ap[0]==n)
{
    for(i=1;i<=n;i++)
        if(a[i]==1) break;
    t=i-1;
    for(i=n;i>=1;i--)
        if(a[i]==1) break;
    s=i;
    printf("%d %d\n",s,t);
    return 0;
}
else
if(ap[2]+ap[0]==n)
{
    for(i=1;i<=n;i++)
        if(a[i]==2) break;
    s=i;
    for(i=n;i>=1;i--)
        if(a[i]==2) break;
    t=i+1;
    printf("%d %d\n",s,t);
    return 0;
}
if(pr[2]<pr[1])
{
    s=pr[2];
    t=pr[1]-1;
    printf("%d %d\n",s,t);
    return 0;
}
////pr[1]<pr[2];
for(i=1;i<=n;i++)
    i--;
return 0;
}