#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int cnt=1,n,h,d;
int main()
{
    n=read();d=read();h=read();
    if(d>2*h||d<h)return 0*puts("-1");
    if(d==1&&h==1&&n>2) return 0*puts("-1");
    for(int i=1,pre=1;i<=h;++i) printf("%d %d\n",pre,++cnt),pre=cnt;
    for(int i=1,pre=1;i<=d-h;++i) printf("%d %d\n",pre,++cnt),pre=cnt;
    for(;cnt<n;) printf("%d %d\n",1+(d==h),++cnt);
    return 0;
}