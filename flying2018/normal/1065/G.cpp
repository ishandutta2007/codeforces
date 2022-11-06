#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define N 1010
#define ll long long
using namespace std;
string g[N],sf[N];
map<string,int>ex[4];
int n,m;ll k;
void make(string &x,string &y,map<string,int>& ex)
{
    int n1=x.size()-1,n2=y.size();
    for(int i=n1;i>=n1-m;i--)
        for(int j=1;j<=n2 && n1-i+1+j<=m;j++)
        ex[x.substr(i)+y.substr(0,j)]++;
}
int p[N],s[N];ll f[N];
ll check(string x)
{
    int cnt[4]={ex[0][x],ex[1][x],ex[2][x],ex[3][x]};
    f[14]=f[15]=0;
    for(int i=0;i<g[14].size()-x.size();i++)
    if(g[14].substr(i,i+x.size())==x) f[14]++;
    p[14]=s[14]=0;
    for(int i=0;i<g[15].size()-x.size();i++)
    if(g[15].substr(i,i+x.size())==x) f[15]++;
    p[15]=s[15]=1;
    for(int i=16;i<=n;i++)
    {
        f[i]=f[i-2]+f[i-1]+cnt[s[i-2]<<1|p[i-1]];
        if(f[i]>k) return k+1;
        p[i]=p[i-2];s[i]=s[i-1];
    }
    return f[n];
}
string res;
int main()
{
    scanf("%d%lld%d",&n,&k,&m);
    g[0]="0",g[1]="1";
    for(int i=2;i<=15;i++) g[i]=g[i-2]+g[i-1];
    if(n<=15)
    {
        int p=g[n].size();
        for(int i=0;i<p;i++) sf[i]=g[n].substr(i,p);
        sort(sf,sf+p);
        for(int i=0;i<min((int)sf[k-1].size(),m);i++) putchar(sf[k-1][i]);
        return 0;
    }
    make(g[14],g[14],ex[0]);
    make(g[14],g[15],ex[1]);
    make(g[15],g[14],ex[2]);
    make(g[15],g[15],ex[3]);
    for(int i=0;i<m;i++)
    {
        ll c=check(res+"0");
        if(c>k) res+="0";
        else res+="1",k-=c;
        if(!k) break;
    }
    cout<<res;
    return 0;
}