#include<iostream>
#include<cstdio>
#include<cstring>
#define N 21
#define ull unsigned long long
#define db double
using namespace std;
char s[55][N];
db f[1<<N];// s 
ull g[1<<N];
inline int count(ull a){return __builtin_popcountll(a);}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%s",s[i]);
    int m=strlen(s[0]),M=(1<<m)-1;
    for(int i=0;i<n;i++)
        for(int j=i+1,r;j<n;g[r]|=(1ull<<i)|(1ull<<j),j++)
            for(int k=r=0;k<m;k++) r|=(s[i][k]==s[j][k])<<k;
    for(int i=M;i>=1;i--)
        for(int j=0;j<m;j++)
        if(i&(1<<j)) g[i^(1<<j)]|=g[i];
    for(int u=M-1;u>=0;u--)
    if(g[u])
    {
        f[u]=1;
        for(int i=0;i<m;i++)
        if(!((u>>i)&1))
        {
            int v=u|(1<<i);
            f[u]+=f[v]/(m-count(u))*count(g[v])/count(g[u]);
        }
    }
    printf("%.10f\n",f[0]);
    return 0;
}