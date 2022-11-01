#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
typedef array<int,2> pii;
const int N=1E6+10;
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
bool a[N];
int q[N];
int main()
{
    int n=read(),m=read();
    for(int i=1,p=1;i<=n;++i)
    {
        for(int j=1;j<=m;++j,++p)
        {
            char c;
            do c=getchar();while(c<46);
            a[p]=c^46;
            if(i^1&&j^1&&a[p-1]&&a[p-m])q[j]=1;
        }
    }
    for(int i=1;i<=m;++i)q[i]+=q[i-1];
    for(int T=read();T--;)puts(q[read()]^q[read()]?"NO":"YES");
}