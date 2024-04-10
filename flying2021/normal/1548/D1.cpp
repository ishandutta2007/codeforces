#include<iostream>
#include<cstdio>
#include<cstring>
#define N 6010
#define ll long long
using namespace std;
int x[N],y[N];
int c[4];
bool check(int x,int y,int z){return (x==y || x==z || y==z);}
ll c3(int x){return 1ll*x*(x-1)*(x-2)/6;}
ll c2(int x,int y){return 1ll*x*(x-1)*y/2;}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]);
    for(int i=1;i<=n;i++) c[x[i]%4+(y[i]%4)/2]++;
    ll ans=0;
    for(int i=0;i<4;i++)
        for(int j=i;j<4;j++)
            for(int k=j;k<4;k++)
            if(check(i,j,k) && c[i] && c[j] && c[k])
            {
                if(i==j && j==k) ans+=c3(c[i]);
                else if(i==j) ans+=c2(c[i],c[k]);
                else if(j==k) ans+=c2(c[j],c[i]);
                else ans+=c2(c[i],c[j]);
            }
    printf("%lld\n",ans);
    return 0;
}