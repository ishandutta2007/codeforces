#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define forinc(a,b,c) for(int a=b,_c=c;a<=_c;++a)
#define fordec(a,b,c) for(int a=b,_c=c;a>=_c;--a)
#define forv(a,b) for(auto&a:b)
#define getb(i) (i-1)/T+1
#define daub(i) (i-1)*T+1
#define cuoib(i) i*T
using namespace std;
const int N=200010;
int n,q,T,a[N],th[450][N],vt[N],b[N];
void update(int a,int b,int x)
{
    for(int i=a;i<=getb(n);i+=i&-i)
    for(int j=b;j;j-=j&-j) th[i][j]+=x;
}
int get(int a,int b)
{
    int g=0;
    for(int i=a;i;i-=i&-i)
    for(int j=b;j<=n;j+=j&-j)
    g+=th[i][j];
    return g;
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int query(int i,int j,int k)
{
    //cout<<i<<" "<<j<<" "<<k<<endl;
    if(k==n+1) return 0;
    int I=getb(i),J=getb(j);
    int tg=0;
    if(abs(I-J)<2)
    {
        //cout<<i<<" "<<j<<" "<<k<<endl;
        forinc(o,i,j) if(a[o]>=k) tg++;
        return tg;
    }
    forinc(o,i,cuoib(I)) if(a[o]>=k) tg++;
    forinc(o,daub(J),j) if(a[o]>=k) tg++;
    tg+=get(J-1,k)-get(I,k);
    return tg;
}
int main()
{
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    read(n);read(q);T=sqrt(n);
    forinc(i,1,n) {read(a[i]);vt[a[i]]=i;}
    forinc(i,1,n)
    {
        read(b[i]);a[i]=vt[b[i]];
        update(getb(i),a[i],1);
    }
    while(q--)
    {
        int c,u,v,i,j;
        read(c);read(i);read(j);
        if(c==2)
        {
            int v1=a[i],v2=a[j];
            update(getb(i),a[i],-1);a[i]=v2;
            update(getb(i),a[i],1);
            update(getb(j),a[j],-1);a[j]=v1;
            update(getb(j),a[j],1);
            continue;
        }
        read(u);read(v);
        cout<<query(u,v,i)-query(u,v,j+1)<<"\n";
    }
}