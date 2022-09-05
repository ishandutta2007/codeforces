#include<cstdio>
#include<cstring>
using namespace std;
int i,j,k,l,n,m,ap[1009][2],unu[1009],dp[1009];
char a[1009],b[1009];
int catide1(int i,int j,int k)
{
    ////ultimele i din A si [j,k] din B
    return ap[n][1]-ap[n-i][1]+unu[k]-unu[j-1];
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(a+1);
gets(b+1);
n=strlen(a+1);
m=strlen(b+1);
for(i=1;i<=n;i++)
{
    ap[i][0]=ap[i-1][0];
    ap[i][1]=ap[i-1][1];
    ap[i][a[i]-48]++;
}
for(i=1;i<=m;i++)
    unu[i]=unu[i-1]+(b[i]=='1');
for(l=0;l<=n;l++)
{
    for(i=1;i<=l;i++)
        if(b[i]!=a[n-l+i]) break;
    if(i<=l) continue;
    dp[0]=0;
    for(j=1;j<=m-l;j++)
    {
        if(b[l+j]=='0') dp[j]=dp[j-1];
        else
        {
            for(k=dp[j-1];k<=n-l;k++)
                if(b[l+j]-48==catide1(n-k,l+1,l+j-1)%2) break;
            if(k>n-l) break;
            else dp[j]=k;
        }
    }
    if(j<=m-l) continue;
    printf("YES\n");
    return 0;
}
printf("NO\n");
return 0;
}