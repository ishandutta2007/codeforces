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
const int N=2e5+10;
int m,n,a[N],f[N];
struct oo {int u,v,c;} e[N];
bool cmp(oo u,oo v)
{
    return u.c>v.c;
}
int main()
{
    //freopen("1214E.inp","r",stdin);
    n=in;
    forinc(i,1,n) e[i]={2*i-1,2*i,in};
    sort(e+1,e+n+1,cmp);
    int i=1;
    int pre=e[i].u;
    int top=0;
    int j=i+1;
    while(--e[j-1].c)
    {
        i++;
        cout<<pre<<" "<<e[i].u<<"\n";
        f[++top]=e[i].u;
        pre=e[i].u;
    }
    cout<<pre<<" "<<e[j-1].v<<"\n";
    f[++top]=e[j-1].v;
    pre=e[j-1].v;
    top=0;
    while(j<=i)
    {
        cout<<f[e[j].c+(top++)]<<" "<<e[j].v<<"\n";
        if(f[e[j].c+top-1]==pre) f[e[j].c+top]=e[j].v,pre=e[j].v;
        ++j;
    }
    while(i<n)
    {
        ++i;
        cout<<e[1].u<<" "<<e[i].u<<"\n";
        if(e[i].c==1) cout<<e[i].u<<" "<<e[i].v<<"\n";
        else if(e[i].c==2) cout<<e[1].u<<" "<<e[i].v<<"\n";
        else cout<<f[e[i].c-2]<<" "<<e[i].v<<"\n";
    }
}