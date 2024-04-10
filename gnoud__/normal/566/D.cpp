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
const int N=200010;
int n,q,id[N],it[N],dd[N];
int root(int x) {return id[x]<0?x:id[x]=root(id[x]);}
int nex(int x) {return (!it[x])?x:it[x]=nex(it[x]);}
void unions(int u,int v)
{
    if((u=root(u))==(v=root(v))) return;
    if(id[u]>id[v]) swap(u,v);
    id[u]+=id[v];
    id[v]=u;
}
void read(int & x)
{
    x=0;char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
}
int main()
{
    //freopen("566D.inp","r",stdin);
    reset(id,-1);
    read2(n,q);
    while(q--)
    {
        int c,u,v;
        read3(c,u,v);
        if(c==3) cout<<((root(u)==root(v))?"YES":"NO")<<"\n";
        else if(c==1) unions(u,v);
        else for(;nex(u)<v;u=nex(u))
        {
            unions(u,nex(u)+1);
            it[u]=nex(u)+1;
        }
    }
}