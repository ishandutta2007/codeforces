#include<iostream>
#include<cstdio>
using namespace std;
int n,ch[1000001][2],tag[1000001];
bool flag[1000001],val[1000001];
inline int read()
{
    int x=0;
    char c=getchar();
    while(c<'0'||c>'9')
        c=getchar();
    while(c>='0'&&c<='9')
    {
        x=(x<<1)+(x<<3)+(c^48);
        c=getchar();
    }
    return x;
}
inline void dfs1(int k)
{
    if(ch[k][0])
        dfs1(ch[k][0]);
    if(ch[k][1])
        dfs1(ch[k][1]);
    if(tag[k]==1)
    {
        val[k]=val[ch[k][0]]&val[ch[k][1]];
        flag[ch[k][0]]=!val[ch[k][1]];
        flag[ch[k][1]]=!val[ch[k][0]];
    }
    if(tag[k]==2)
    {
        val[k]=val[ch[k][0]]|val[ch[k][1]];
        flag[ch[k][0]]=val[ch[k][1]];
        flag[ch[k][1]]=val[ch[k][0]];
    }
    if(tag[k]==3)
        val[k]=val[ch[k][0]]^val[ch[k][1]];
    if(tag[k]==4)
        val[k]=!val[ch[k][0]];
}
inline void dfs2(int k)
{
    if(ch[k][0])
    {
        flag[ch[k][0]]|=flag[k];
        dfs2(ch[k][0]);
    }
    if(ch[k][1])
    {
        flag[ch[k][1]]|=flag[k];
        dfs2(ch[k][1]);
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)
    {
        char opt=getchar();
        while(opt!='A'&&opt!='O'&&opt!='X'&&opt!='N'&&opt!='I')
            opt=getchar();
        if(opt=='A')
            tag[i]=1;
        if(opt=='O')
            tag[i]=2;
        if(opt=='X')
            tag[i]=3;
        if(opt=='N')
            tag[i]=4;
        if(opt=='I')
            tag[i]=5;
        if(opt=='N')
            ch[i][0]=read();
        else if(opt=='I')
            val[i]=read();
        else
            ch[i][0]=read(),ch[i][1]=read();
    }
    dfs1(1);
    dfs2(1);
    for(int i=1;i<=n;++i)
        if(tag[i]==5)
            putchar((val[1]^flag[i]^1)+'0');
    putchar('\n');
    return 0;
}