#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int nr,sum,A,i,j,n,s[4009],x[4009],ap[36009];
char sir[4009];
long long sol;
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
scanf("%d\n",&A);
gets(sir+1);
n=strlen(sir+1);
for(i=1;i<=n;i++)
{
    x[i]=sir[i]-48;
    sum+=x[i];
    s[i]=s[i-1]+x[i];
}
for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)
    {
        ap[s[j]-s[i-1]]++;
        nr++;
    }
if(A==0)
{
    for(i=1;i<=n;i++)
        for(j=i;j<=n;j++)
        {
            if(s[j]-s[i-1]==0)
                sol+=nr;
            else sol+=ap[0];
        }
    printf("%I64d\n",sol);
    return 0;
}
for(i=1;i<=n;i++)
    for(j=i;j<=n;j++)
    if(s[j]-s[i-1]!=0)
    {
        if(A%(s[j]-s[i-1])==0)
        {
            if(A/(s[j]-s[i-1])<=sum) sol+=ap[A/(s[j]-s[i-1])];
            else ;
        }
    }
printf("%I64d\n",sol);
return 0;
}