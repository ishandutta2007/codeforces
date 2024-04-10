#include<cstdio>
#include<cstring>
using namespace std;
int sum,num,cnt,nmax,i,j,k,n,sau,ap[44723];
long long p;
//char sg[1<<28];
int sg[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12};
int main()
{
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
/*scanf("%d",&nmax);
for(n=25;n<=nmax;n++)
{
    sg[0]=0;
    for(i=1;i<(1<<n);i++)
    {
        memset(ap,0,sizeof(ap));
        for(j=1;j<=n;j++)
        if(i&(1<<(j-1)))
        {
            sau=0;
            for(k=1;k*j<=n;k++)
                if(i&(1<<(k*j-1))) sau|=(1<<(k*j-1));
            ap[sg[i-sau]]=1;
        }
        for(j=0;j<=10000;j++)
            if(ap[j]==0) break;
        sg[i]=j;
    }
    printf("%d\n",sg[(1<<n)-1]);
}*/
scanf("%d",&n);
num=n-1;
sum=sg[1];
for(i=2;i*i<=n;i++)
if(ap[i]==0)
{
    p=i;
    cnt=1;
    while(1)
    {
        p=1LL*p*i;
        if(p>n) break;
        cnt++;
        if(1LL*p*p<=n) ap[p]=1;
    }
    sum^=sg[cnt];
    num-=cnt;
}
num%=2;
if(num) sum^=sg[1];
if(sum) printf("Vasya\n");
else printf("Petya\n");
return 0;
}