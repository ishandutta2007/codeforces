#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define in ({int x=0;int c=getchar(),n=0;for(;!isdigit(c);c=getchar()) n=(c=='-');for(;isdigit(c);c=getchar()) x=x*10+c-'0';n?-x:x;})
#define ins ({string x;char c=getchar();for(;c==' '||c=='\n';c=getchar());for(;c!=' '&&c!='\n';c=getchar()) x+=c;x;})
#define forinc(i,a,b) for(int i=a,_b=b;i<=_b;++i)
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
#define id(x,y) ((x-1)*n+y)
const int N=3000010;
int m,n,a[N],dd[N];
bool DFS(int u,int v)
{
    if(u==m&&v==n) return 1;
    dd[id(u,v)]=1;
    if(u!=m&&!dd[id(u+1,v)]&&!a[id(u+1,v)]&&DFS(u+1,v)) return 1;
    if(v!=n&&!dd[id(u,v+1)]&&!a[id(u,v+1)]&&DFS(u,v+1)) return 1;
    return 0;
}
int main()
{
    //freopen("1214D.inp","r",stdin);
    m=in,n=in;
    forinc(i,1,m) forinc(j,1,n)
    {
        char c=getchar();
        while(c!='.'&&c!='#') c=getchar();
        a[id(i,j)]=(c=='#');
    }
    if(!DFS(1,1)) return cout<<0,0;
    if(!DFS(1,1)) return cout<<1,0;
    cout<<2;
}