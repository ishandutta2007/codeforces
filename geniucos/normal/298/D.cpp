#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int nr,n,m,k,i,val,ula,ulb,apa[200009],apb[200009],a[100009],b[100009],cata[200009],catb[200009],sa[200009],sb[200009];
struct str
{
    int v,poz;
};
str so[200009];
bool cmp(str a,str b)
{
    return a.v<b.v;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&k);
for(i=1;i<=n;i++)
{
    scanf("%d",&a[i]);
    nr++;
    so[nr].v=a[i];
    so[nr].poz=-i;
}
for(i=1;i<=m;i++)
{
    scanf("%d",&b[i]);
    nr++;
    so[nr].v=b[i];
    so[nr].poz=i;
}
sort(so+1,so+nr+1,cmp);
so[0].v=0;
val=0;
for(i=1;i<=nr;i++)
{
    if(so[i].v!=so[i-1].v) val++;
    if(so[i].poz<0) a[so[i].poz*-1]=val;
    else b[so[i].poz]=val;
}
for(i=1;i<=n;i++)
    apa[a[i]]++;
for(i=1;i<=m;i++)
    apb[b[i]]++;
for(i=1;i<=val;i++)
{
    if(apa[i]>apb[i]) cata[i]=apa[i]-apb[i];
    else
    if(apa[i]<apb[i]) catb[i]=apb[i]-apa[i];
}
for(i=val;i>=1;i--)
    sa[i]=sa[i+1]+cata[i];
for(i=val;i>=1;i--)
    sb[i]=sb[i+1]+catb[i];
for(i=1;i<=val;i++)
    if(sa[i]>sb[i])
    {
        printf("YES\n");
        return 0;
    }
printf("NO\n");
return 0;
}