#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define db double
#define N 400010
using namespace std;
int x[N],y[N];
db dis(int a,int b){return sqrt(1.0*a*a+1.0*b*b);}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0)
    {
        int n;
        scanf("%d",&n);
        int mx=0,my=0;
        for(int i=1;i<=n*2;i++) x[i]=y[i]=0;
        for(int i=1;i<=n*2;i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a<0) a=-a;if(b<0) b=-b;
            if(a==0 && b==0) continue;
            if(a==0) y[++my]=b;
            else x[++mx]=a;
        }
        sort(x+1,x+mx+1);
        sort(y+1,y+my+1);
        db ans=0;
        for(int i=1;i<=n;i++) ans+=dis(x[i],y[i]);
        printf("%.11lf\n",ans);
    }
    return 0;
}