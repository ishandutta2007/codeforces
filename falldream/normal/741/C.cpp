#include<bits/stdc++.h>
#define MN 200000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,s[MN+5],c[MN+5],a[MN+5],b[MN+5];
void Mark(int x,int y)
{
    c[x]=y;
    int rev=(x&1)?x+1:x-1;
    if(!c[rev]) Mark(rev,y^3);
    if(!c[s[x]]) Mark(s[x],y^3);
}
int main()
{   
    n=read();
    for(int i=1;i<=n;++i) a[i]=read(),b[i]=read(),s[a[i]]=b[i],s[b[i]]=a[i];
    for(int i=1;i<=n<<1;++i) if(!c[i]) Mark(i,1);
    for(int i=1;i<=n;++i) printf("%d %d\n",c[a[i]],c[b[i]]);
    return 0;
}