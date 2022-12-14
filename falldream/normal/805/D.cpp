#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
#include<set>
#include<map>
#define ll long long
#define pa pair<int,int>
#define mp(x,y) make_pair(x,y)
#define mod 1000000007
#define MN 1000000
using namespace std;
inline int read()
{
    int x = 0,f = 1; char ch = getchar();
    while(ch < '0' || ch > '9'){if(ch == '-') f = 0;ch = getchar();}
    while(ch >= '0' && ch <= '9'){x = x * 10 + ch - '0';ch = getchar();}
    return f?x:-x;
}

int s[MN+5],ans=0;
char st[MN+5];

int main()
{
    scanf("%s",st+1);
    for(int i=1,j=2;i<=MN+1;++i,j=(j<<1)%mod)
        s[i]=j;
    for(int i=1,k=0;st[i];++i)
        if(st[i]=='a') ++k;
        else (ans+=(k==0?0:s[k]-1))%=mod;
    printf("%d\n",ans);
    return 0;
}