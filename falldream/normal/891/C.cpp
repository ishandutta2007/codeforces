#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define MN 500000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long long L[MN+5],R[MN+5];
int n,m,Q,X[MN+5],Y[MN+5],W[MN+5],rk[MN+5],s[MN+5],num;
map<long long,int> mp;
inline int getfa(int x){return s[x]?s[x]=getfa(s[x]):x;}
bool cmpw(int x,int y){return W[x]<W[y];}
int main()
{
    n=read();m=read();
    for(int i=1;i<=m;++i) X[i]=read(),Y[i]=read(),W[i]=read(),rk[i]=i;
    sort(rk+1,rk+m+1,cmpw);
    for(int i=1,j;i<=m;i=j+1)
    {
        for(j=i;j<m&&W[rk[j+1]]==W[rk[i]];++j);
        for(int k=i;k<=j;++k) L[rk[k]]=1LL*W[rk[i]]*m+getfa(X[rk[k]]),R[rk[k]]=1LL*W[rk[i]]*m+getfa(Y[rk[k]]);
        for(int k=i;k<=j;++k) if(getfa(X[rk[k]])!=getfa(Y[rk[k]])) s[getfa(X[rk[k]])]=getfa(Y[rk[k]]);
    }
    memset(s,0,sizeof(s));
    for(Q=read();Q;--Q)
    {
        int t=read();mp.clear();int flag=1;num=0;
        for(int i=1;i<=t;++i)
        {
            int x=read();
            if(!mp[L[x]]) s[mp[L[x]]=++num]=0;
            if(!mp[R[x]]) s[mp[R[x]]=++num]=0;
            if(getfa(mp[L[x]])==getfa(mp[R[x]])) flag=0;
            else s[getfa(mp[L[x]])]=getfa(mp[R[x]]);
        }
        puts(flag?"YES":"NO");
    }
    return 0;
}