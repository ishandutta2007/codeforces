#include<cstdio>
#include<cstring>
using namespace std;
int a,b,n,i,x[109],y[109];
char sir[109];
int mod(int x)
{
    if(x<0) return -x;
    return x;
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
scanf("%d",&a);
scanf("%d\n",&b);
gets(sir+1);
n=strlen(sir+1);
x[0]=0;
y[0]=0;
for(i=1;i<=n;i++)
{
    x[i]=x[i-1];y[i]=y[i-1];
    if(sir[i]=='U') y[i]++;
    else
    if(sir[i]=='D') y[i]--;
    else
    if(sir[i]=='L') x[i]--;
    else
    if(sir[i]=='R') x[i]++;
    else
    {
        n=i-1;
        break;
    }
}
for(i=0;i<=n;i++)
{
    if(x[n]!=0)
    {
        if((a-x[i])%x[n]!=0) continue;
        if((a-x[i])/x[n]<0) continue;
    }
    else
    if(x[i]!=a) continue;
    if(y[n]!=0)
    {
        if((b-y[i])%y[n]!=0) continue;
        if((b-y[i])/y[n]<0) continue;
    }
    else
    if(y[i]!=b) continue;
    if(x[n]==0||y[n]==0||((a-x[i])/x[n]==(b-y[i])/y[n]))
    {
        printf("Yes\n");
        return 0;
    }
}
printf("No\n");
return 0;
}