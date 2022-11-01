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
#define __ putchar(' ')
#define _n putchar('\n')
const int N=100010;
int n,m,a[N][32],t[N][30],dd[N],id[N],l[N],r[N],c[N];
int root(int x) {return (!dd[x])?x:id[x]=root(id[x+1]);}
void build(int s)
{
    reset(dd,0);
    forinc(i,1,n+1) id[i]=i;
    fordec(I,m,1) if(bit(c[I],s)) for(int i=root(l[I]);i<=r[I];i=root(i+1)) a[i][s]=1,dd[i]=1;
}
int get(int l,int r)
{
    int tg=log2(r-l+1);
    return t[l][tg]&t[r-(1<<tg)+1][tg];
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    //freopen("482B.inp","r",stdin);
    //freopen("482B.out","w",stdout);
    read(n);read(m);
    forinc(i,1,m) read3(l[i],r[i],c[i]);
    forinc(i,1,30) build(i);
    forinc(i,1,n) forinc(j,1,30) if(a[i][j]) t[i][0]+=(1<<(j-1));
    forinc(j,1,log2(n))
    forinc(i,1,n) t[i][j]=t[i][j-1]&t[i+(1<<(j-1))][j-1];
    forinc(i,1,m) if(get(l[i],r[i])!=c[i]) return cout<<"NO",0;
    cout<<"YES\n";
    forinc(i,1,n) cout<<t[i][0]<<" ";
}