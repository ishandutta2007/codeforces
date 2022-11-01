#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1<<13;
const int inf=1<<30;
auto min(auto l,auto r){return l<r?l:r;}
auto max(auto l,auto r){return l>r?l:r;}
void cmin(auto &l,auto r){l=l<r?l:r;}
void cmax(auto &l,auto r){l=l>r?l:r;}
ll read()
{
    ll a=0;
    char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(ll x,char c)
{
    if(x<0)putchar(45),x=-x;
    char a[20],s=0;
    do a[++s]=x%10|48;while(x/=10);
    do putchar(a[s]);while(--s);
    putchar(c);
}
int f[N];
bool b[N];
int main()
{
    for(int i=1;i<N;++i)f[i]=inf;
    for(int n=read();n--;)
    {
        int x=read();
        if(b[x])continue;
        bool flag=0;
        for(int i=0;i<N;++i)
        {
            if(f[i]<x&&f[i^x]>x)
            {
                f[i^x]=x;
                flag=1;
            }
        }
        if(flag)memset(b,0,N);
        else b[x]=1;
    }
    int s=0;
    for(int i=0;i<N;++i)s+=f[i]!=inf;
    write(s,'\n');
    for(int i=0;i<N;++i)if(f[i]^inf)write(i,' ');
}