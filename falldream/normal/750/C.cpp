#include<iostream>
#include<cstdio>
#define INF 22000000
using namespace std;
int read()
{
   int x=0,f=1;char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
   while(ch>='0'&&ch<='9'){x=x*10+ch-'0'; ch=getchar();}
   return x*f;
}

int n;
int d[200005];
int c[200005];

int check(int x)
{
  //  printf("check%d\n",x);
    for(int i=1;i<=n;i++)
    {
      //  printf("%d %d\n",x,d[i]);
        if(x<1900&&d[i]==1) return 3;
        if(x>=1900&&d[i]==2) return 2;
        x+=c[i];
    }
    return 1;
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++)
    {
        c[i]=read();d[i]=read();
    }
    int l=-INF,ans=-INF-1,r=INF,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        int res=check(mid);
        if(res==1){ans=mid;l=mid+1;}
        else if(res==2)r=mid-1;
        else l=mid+1;
    }
    if(ans==INF) printf("Infinity");
    else if(ans<-INF) printf("Impossible");
    else
    {
        for(int i=1;i<=n;i++) ans+=c[i];
        printf("%d",ans);
    }
    return 0;
}