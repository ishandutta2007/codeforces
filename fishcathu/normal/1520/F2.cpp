#include<bits/stdc++.h>
#define ls i<<1
#define rs i<<1|1
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vct;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int N=8E5+10;
const int inf=1<<30;
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
int L[N],R[N],sum[N];
int askk(int l,int r)
{
    printf("? %d %d\n",l,r);
    fflush(stdout);
    return r-l+1-read();
}
void build(int i,int l,int r)
{
    L[i]=l;
    R[i]=r;
    sum[i]=-1;
    if(l!=r)
    {
        int m=l+r>>1;
        build(ls,l,m);
        build(rs,m+1,r);
    }
}
int ask(int i)
{
    if(~sum[i])return sum[i];
    return sum[i]=askk(L[i],R[i]);
}
int getans(int i,int k)
{
    --sum[i];
    if(L[i]==R[i])return L[i];
    int y=ask(ls);
    if(y>=k)return getans(ls,k);
    return getans(rs,k-y);
}
int main()
{
    int n=read(),m=read();
    build(1,1,n);
    while(m--)
    {
        printf("! %d\n",getans(1,read()));
        fflush(stdout);
    }
}