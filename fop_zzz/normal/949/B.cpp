#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<ctime>
#include<cstdlib>
#include<algorithm>
#include<queue>
#define For(i,j,k)    for(int i=j;i<=k;++i)
#define Dow(i,j,k)    for(int i=k;i>=j;--i)
#define ll long long
#define inf 1e9
using namespace std;
inline ll read()
{
    ll t=0,f=1;char c=getchar();
    while(!isdigit(c))    {if(c=='-')    f=-1;c=getchar();}
    while(isdigit(c))    t=t*10+c-'0',c=getchar();
    return t*f;
}
inline void write(ll x){if(x>=10)    write(x/10);putchar(x%10+'0');}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}
ll n;
int q;ll x;
int main(){
    n=read();q=read();
    For(i,1,q)
    {
        x=read();while ((x&1)==0)x+=n-x/2;
        printf("%I64d\n",(x+1)/2);
    } 
}