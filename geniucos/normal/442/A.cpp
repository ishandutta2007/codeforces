#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int n,r,c,A[20][20],i,j,mini,Nr,apc[20],apn[20],ap[20][20],C[109],N[109];
char cul[109],nr[109];
int mod(int x)
{
    if(x<0) return -x;
    return x;
}
void refresh1()
{
    for(c=1;c<=5;c++)
        if(apc[c])
        {
            int c1=0,c2=0;
            for(r=1;r<=5;r++)
            if(ap[c][r])
            {
                c2++;
                if(apn[r]) c1++;
            }
            if(c2-c1==1)
            {
                for(r=1;r<=5;r++)
                    if(ap[c][r]&&apn[r]==0) A[c][r]=1;
            }
        }
}
void refresh2()
{
    for(r=1;r<=5;r++)
        if(apn[r])
        {
            int c1=0,c2=0;
            for(c=1;c<=5;c++)
            if(ap[c][r])
            {
                c2++;
                if(apc[c]) c1++;
            }
            if(c2-c1==1)
            {
                for(c=1;c<=5;c++)
                    if(ap[c][r]&&apc[c]==0) A[c][r]=1;
            }
        }
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d\n",&n);
for(i=1;i<=n;i++)
    scanf("%c%c ",&cul[i],&nr[i]);
for(i=1;i<=n;i++)
    nr[i]-='0';
//R, G, B, Y, W
for(i=1;i<=n;i++)
{
    if(cul[i]=='R') cul[i]=1;
    else
    if(cul[i]=='G') cul[i]=2;
    else
    if(cul[i]=='B') cul[i]=3;
    else
    if(cul[i]=='Y') cul[i]=4;
    else cul[i]=5;
}
for(i=1;i<=n;i++)
{
    ap[cul[i]][nr[i]]=1;
    C[cul[i]]=1;
    N[nr[i]]=1;
}
mini=20;
for(i=0;i<(1<<10);i++)
{
    if(i==56)
        i=56;
    Nr=0;
    for(j=0;j<10;j++)
        apn[j]=apc[j]=0;
    for(j=0;j<10;j++)
        if(i&(1<<j))
        {
            if(j<=4) apc[j+1]=1;
            else apn[j-4]=1;
            Nr++;
        }
    int c1=0,c2=0;
    for(j=1;j<=5;j++)
        if(C[j])
        {
            c2++;
            if(apc[j]) c1++;
        }
    if(c2-c1==1)
    {
        for(j=1;j<=5;j++)
            if(C[j]&&apc[j]==0) apc[j]=1;
    }
    c1=c2=0;
    for(j=1;j<=5;j++)
        if(N[j])
        {
            c2++;
            if(apn[j]) c1++;
        }
    if(c2-c1==1)
    {
        for(j=1;j<=5;j++)
            if(N[j]&&apn[j]==0) apn[j]=1;
    }
    for(c=1;c<=5;c++)
        for(r=1;r<=5;r++)
            A[c][r]=(apc[c]&&apn[r]);
    for(j=1;j<=4;j++)
        refresh1(),refresh2();
    int P=0;
    for(c=1;c<=5;c++)
        for(r=1;r<=5;r++)
            if(A[r][c]==0&&ap[r][c]) P++;
    if(P<=1&&Nr<mini) mini=Nr;
}
printf("%d\n",mini);
return 0;
}