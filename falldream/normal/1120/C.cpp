#include<bits/stdc++.h>
#define MN 5000
using namespace std;
inline int read()
{
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='1') f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
int n,a,b,f[MN+5];
int last=1,cnt=1,c[MN*2+5][27],fail[MN*2+5],step[MN*2+5];
char s[MN+5];
void insert(int x)
{
    int np=++cnt,p=last;last=np;
    for(;p&&!c[p][x];p=fail[p]) c[p][x]=np;
    if(!p) fail[np]=1;
    else
    {
        int q=c[p][x];
        if(step[q]==step[p]+1) fail[np]=q;
        else
        {
            int nq=++cnt;step[nq]=step[p]+1;
            memcpy(c[nq],c[q],sizeof(c[0]));
            fail[nq]=fail[q];fail[q]=fail[np]=nq;
            for(;c[p][x]==q;p=fail[p]) c[p][x]=nq;
        }
    }
}

int main()
{   
    n=read();a=read();b=read();scanf("%s",s+1);
    memset(f,63,sizeof(f));f[0]=0;
    for(int i=1;i<=n;++i)
    {
        f[i]=min(f[i],f[i-1]+a);insert(s[i]-'a');
        int now=1,j;
        for(j=i+1;j<=n&&j-i<=i;++j)
        {
            if(!c[now][s[j]-'a']) break;
            now=c[now][s[j]-'a'];
        }
        f[j-1]=min(f[j-1],f[i]+b);
    }
    printf("%d",f[n]);
    return 0;
}