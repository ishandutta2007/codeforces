#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define eps 1e-8
#define MN 1000
#define ll long long
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}
inline double sqr(double x){return x*x;}
struct P
{
    double x,y;
    P(double _x=0,double _y=0):x(_x),y(_y){}
    double operator^(P b){return fabs(x*b.y-b.x*y);}
    P operator-(P b){return P(x-b.x,y-b.y);}
    friend double dis(P a,P b){return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));}
}p[MN+5];

int n;
double ans=1e18;

int main()
{
    n=read();
    for(int i=1;i<=n;i++) p[i].x=read(),p[i].y=read();
    for(int i=1;i<n;i++) ans=min(ans,dis(p[i],p[i+1])/2.0);
    ans=min(ans,dis(p[n],p[1])/2.0);
    p[n+1]=p[1];p[n+2]=p[2];
    for(int i=1;i<=n;i++)
        ans=min(ans,((p[i]-p[i+1])^(p[i+2]-p[i+1]))/dis(p[i],p[i+2])/2);
    printf("%0.7lf\n",ans);
    return 0;
}