#include<cstdio>
using namespace std;
int val,i,n,m,ci,ti,dur[100005],curent,s;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
for(i=1;i<=n;i++)
{
    scanf("%d",&ci);
    scanf("%d",&ti);
    dur[i]=ci*ti;
}
curent=1;
s=dur[1];
for(i=1;i<=m;i++)
{
    scanf("%d",&val);
    while(val>s)
    {
        curent++;
        s=s+dur[curent];
    }
    printf("%d\n",curent);
}
return 0;
}