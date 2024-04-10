#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define forinc(i,a,b) for(int i=a;i<=b;++i)
#define fordec(i,a,b) for(int i=a;i>=b;--i)
#define forv(a,b) for(auto &a:b)
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
#define all(a) a.begin(),a.end()
#define reset(f,x) memset(f,x,sizeof(f))
#define bit(x,i) ((x>>(i-1))&1)
#define onbit(x,i) (x|(1<<(i-1)))
#define offbit(x,i) (x&~(1<<(i-1)))
#define read2(a,b) read(a),read(b)
#define read3(a,b,c) read(a),read(b),read(c)
const int N=4e5+10;
int n,a[N],t[4*N],s[N];
void build(int s,int l,int r)
{
    t[s]=N;
    if(l==r) return;
    int mid=(l+r)/2;
    build(2*s,l,mid);
    build(2*s+1,mid+1,r);
}
void update(int s,int l,int r,int i,int x)
{
    if(l>i || i>r) return;
    if(l==r)  {t[s]=x;return;}
    int m=(l+r)/2;
    update(2*s,l,m,i,x);
    update(2*s+1,m+1,r,i,x);
    t[s]=min(t[s*2],t[s*2+1]);
}
int get(int s,int l,int r,int u,int v)
{
    if(l>v||r<u) return N;
    if(l>=u&&r<=v) return t[s];
    int mid=(l+r)/2;
    return min(get(2*s,l,mid,u,v),get(2*s+1,mid+1,r,u,v));
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    //reopen("E.inp","r",stdin);
    read(n);
    build(1,0,2*n);
    forinc(i,1,n) read(a[i]);
    forinc(i,1,n)
    {
        int x;read(x);
        s[x]++;
        update(1,0,2*n,x,x);
        update(1,0,2*n,x+n,x+n);
    }
    forinc(i,1,n)
    {
        int c=get(1,0,2*n,n-a[i],2*n);
        cout<<(a[i]+c)%n<<" ";
        if(c>=n) c-=n;
        if(!(--s[c]))
        {
            update(1,0,2*n,c,1e9);
            update(1,0,2*n,c+n,1e9);
        }
    }
}