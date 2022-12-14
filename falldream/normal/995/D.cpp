#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long long sum;
int n,m,a[1<<18];
int main()
{
    n=1<<read();m=read();
    for(int i=0;i<n;++i) sum+=(a[i]=read());
    printf("%.10lf\n",(double)sum/n);
    for(int i=1;i<=m;++i)
    {
        int x=read();
        sum-=a[x];sum+=(a[x]=read());
        printf("%.10lf\n",(double)sum/n);
    }
    return 0;
}