#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int st,dr,nr,ai,i,n,b[300009],c[300009],ap[300009];
long long val,maxi,s[300009];
vector < int > h;
struct str
{
    int v,p;
};
str a[300009];
bool cmp(str a,str b)
{
    return a.v<b.v;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
{
    scanf("%d",&ai);
    b[i]=ai;
    s[i]=s[i-1];
    if(ai>=0) s[i]+=ai;
    a[i].v=ai;
    a[i].p=i;
}
sort(a+1,a+n+1,cmp);
maxi=-3000000000000000;
a[0].v=a[1].v+1;
nr=0;
for(i=1;i<=n;i++)
{
    if(a[i].v!=a[i-1].v) nr++;
    c[a[i].p]=nr;
}
for(i=1;i<=n;i++)
{
    if(ap[c[i]]==0) ap[c[i]]=i;
    else
    {
        val=s[i]-s[ap[c[i]]-1];
        if(b[i]<0) val+=2*b[i];
        if(val>maxi)
        {
            maxi=val;
            st=ap[c[i]];
            dr=i;
        }
    }
}
for(i=1;i<st;i++)
    h.push_back(i);
for(i=st+1;i<dr;i++)
    if(b[i]<0) h.push_back(i);
for(i=dr+1;i<=n;i++)
    h.push_back(i);
printf("%I64d %d\n",maxi,h.size());
for(i=0;i<h.size();i++)
    printf("%d ",h[i]);
return 0;
}