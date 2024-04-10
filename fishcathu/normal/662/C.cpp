#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1<<20;
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
ll a[N],b[N];
int s;
void fwt(ll *a)
{
    for(int i=2,j=1;j<s;i<<=1,j<<=1)
    {
        for(int x=0;x<s;x+=i)
        {
            for(int y=0;y<j;++y)
            {
                ll u=a[x+y],v=a[x+y+j];
                a[x+y]=u+v;
                a[x+y+j]=u-v;
            }
        }
    }
}
int main()
{
    int n=read();
    s=1<<n;
    vector<int>vt(read());
    for(int i=1;i<s;i<<=1)
    {
        for(int &x:vt)
        {
            char c;
            do c=getchar();while(c<48);
            if(c&1)x+=i;
        }
    }
    for(int x:vt)++a[x];
    for(int i=0;i<s;++i)
    {
        int t=__builtin_popcount(i);
        b[i]=min(t,n-t);
    }
    fwt(a);
    fwt(b);
    for(int i=0;i<s;++i)a[i]*=b[i];
    fwt(a);
    write(*min_element(a,a+s)/s,'\n');
}