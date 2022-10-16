#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define scanf abc=scanf
#define uu unsigned
int abc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef vector<int>VI;
mt19937 rnd((ull)(new char));
int rd(int l,int r){uniform_int_distribution<>ee(l,r);return ee(rnd);}

const int mxn=3e5+3;
int n,a[mxn],b[mxn],d[mxn],qu[mxn],qh,qt,ans[mxn];pii fr[mxn];
struct ussss{int f[mxn];void ii(){for(int i=1;i<=n;++i)f[i]=i;}int fi(int x){while(x!=f[x])x=f[x]=f[f[x]];return x;}void mer(int x){f[x]=fi(x-1);}}u;
bool chk(){
    u.ii();
    qh=qt=1,memset(d,0x3f,sizeof(d)),d[n]=0,qu[1]=n;while(qh<=qt){
        int x=qu[qh++],U=x-a[x];
        if(U==0){
            printf("%d\n",d[x]+1);
            for(int i=x,j=d[x];j;--j,i=fr[i].second)ans[j]=fr[i].first;
            for(int i=1;i<=d[x]+1;++i)printf("%d ",ans[i]);puts("");
            return 1;
        }
        for(int i=u.fi(x);i>=U;u.mer(i),i=u.fi(i)){
            if(d[x]+1<d[i+b[i]])d[i+b[i]]=d[x]+1,qu[++qt]=i+b[i],fr[i+b[i]]={i,x};
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);for(int i=1;i<=n;++i)scanf("%d",a+i);for(int i=1;i<=n;++i)scanf("%d",b+i);
    if(!chk())puts("-1");
    return 0;
}