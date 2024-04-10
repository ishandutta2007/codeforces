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
const int N=1e6+10;
int n,m,a[N],d[N],id[N],dd[N];
ll t[N];
void update(int i,int x)
{
    for(;i<=n;i+=i&-i) t[i]+=x;
}
ll get(int i)
{
    ll g=0;
    for(;i;i-=i&-i) g+=t[i];
    return g;
}
ll sum(int l,int r)
{
    return get(r)-get(l-1);
}
int nex(int x) {return (id[x]==x)?x:id[x]=nex(id[x]);}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
void snt()
{
    forinc(i,1,N-10)
    for(int j=i;j<=N-10;j+=i) d[j]++;
}
int main()
{
    //freopen("920F.inp","r",stdin);
    read2(n,m);
    snt();
    forinc(i,1,n) read(a[i]),update(i,a[i]),id[i]=i;
    id[n+1]=n+1;
    while(m--)
    {
        int c,l,r;
        read3(c,l,r);
        if(c==1)
        {
            while(nex(l)<=r)
            {
                l=nex(l);
                update(l,-a[l]);
                a[l]=d[a[l]];
                update(l,a[l]);
                if(a[l]>2) ++l;
                else id[l]=l+1;
            }
        }
        else cout<<sum(l,r)<<"\n";
    }
}