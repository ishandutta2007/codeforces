#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define N 1000010
#define ull unsigned long long
using namespace std;
char s[3][N];
int n;
ull bs[N],base=233;
struct str_hash{
    ull v[N];
    void init(char s[]){for(int i=1;i<=n;i++) v[i]=v[i-1]*base+s[i];}
    ull get(int l,int r){return v[r]-v[l-1]*bs[r-l+1];}
}h[3];
int nxt[N],nxt2[N];
void get_fail(char s[],char t[],int f[],int i)
{
    int p=0;
    for(;i<=n;i++)
    {
        while(p && s[p+1]!=t[i]) p=nxt[p];
        if(s[p+1]==t[i]) ++p;
        f[i]=p;
    }
}
int main()
{
    gets(s[0]+1);gets(s[1]+1);
    n=strlen(s[0]+1);
    if(strlen(s[1]+1)!=n){puts("-1 -1");return 0;}
    memcpy(s[2],s[0],sizeof(s[2]));
    reverse(s[2]+1,s[2]+n+1);
    bs[0]=1;
    for(int i=1;i<=n;i++) bs[i]=bs[i-1]*base;for(int _=0;_<=2;_++) h[_].init(s[_]);
    int p=0;
    get_fail(s[2],s[2],nxt,2);
    get_fail(s[2],s[1],nxt2,1);
    int al=-1,ar=-1;
    for(int i=1;i<n;i++)
    {
        int u=nxt2[i];
        if(!u) continue;
        if(u==i) u=1;
        if(h[1].get(1,i-u)==h[0].get(n-i+1,n-u) && h[1].get(i+1,n)==h[2].get(i+1,n))
        {
            int l=n-i-1,r=n-u;
            if(al<l || (al==l && ar>r)) al=l,ar=r;
        }
    }
    printf("%d %d\n",al,ar);
    return 0;
}