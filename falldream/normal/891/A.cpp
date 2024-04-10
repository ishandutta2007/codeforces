#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 2000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,a[MN+5],ans=1e9,num=0;
inline int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main()
{
    n=read();
    for(int i=1;i<=n;++i) num+=(a[i]=read())==1;
    if(num) return 0*printf("%d\n",n-num);
    for(int i=1;i<=n;++i)
        for(int j=i+1,k=a[i];j<=n;++j)
            if((k=gcd(k,a[j]))==1) ans=min(ans,n-1+j-i);
    printf("%d\n",ans==1e9?-1:ans);
    return 0;
}