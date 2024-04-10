#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int maxi,st,dr,i,j,n,m,s[5009],ap[5009];
char a[5009][5009];
vector < int > v[5009];
vector < int > :: iterator it;
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
scanf("%d %d\n",&n,&m);
for(i=1;i<=n;i++)
    gets(a[i]+1);
for(i=1;i<=n;i++)
{
    st=0;
    for(j=1;j<=m;j++)
    {
        if(a[i][j]=='1')
        {
            if(st==0) st=dr=j;
            else dr++;
        }
        else
        {
            v[st].push_back(dr);
            st=0;
        }
    }
    if(st!=0) v[st].push_back(dr);
}
maxi=0;
for(i=1;i<=m;i++)
{
    for(it=v[i].begin();it!=v[i].end();it++)
        ap[*it]++;
    for(j=m;j>=1;j--)
        s[j]=s[j+1]+ap[j];
    for(j=i;j<=m;j++)
        if(s[j]*(j-i+1)>maxi) maxi=s[j]*(j-i+1);
}
printf("%d\n",maxi);
return 0;
}