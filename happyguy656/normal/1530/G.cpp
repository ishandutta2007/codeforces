#include<bits/stdc++.h>
using namespace std;
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
int abc;
typedef pair<int,int>pii;
typedef long long ll;
typedef uu long long ull;
typedef vector<int>VI;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

int n,m,nn,p1[2003],p2[2003],p3[2003];char s1[2003],s2[2003];
int m1,m2,a1[4003][2],a2[4003][2];
void cz(int x,bool tp,int k=0){
    int y=x+m-1;
    if(tp){
        int l=p2[x],r=p2[y];
        if(k>=0){l-=k;for(int i=y;i>=x;--i)p3[x+y-i]=l+p2[y]-p2[i];}
        else{r-=k;for(int i=x;i<=y;++i)p3[x+y-i]=r-(p2[i]-p2[x]);}
        for(int i=x;i<=y;++i)p2[i]=p3[i];
        a2[++m2][0]=l,a2[m2][1]=r;
    }else{
        int l=p1[x],r=p1[y];
        if(k>=0){l-=k;for(int i=y;i>=x;--i)p3[x+y-i]=l+p1[y]-p1[i];}
        else{r-=k;for(int i=x;i<=y;++i)p3[x+y-i]=r-(p1[i]-p1[x]);}
        for(int i=x;i<=y;++i)p1[i]=p3[i];
        a1[++m1][0]=l,a1[m1][1]=r;
    }
}
bool wk(){
    m1=m2=0;
    int n1=0,n2=0;for(int i=1;i<=n;++i)if(s1[i])p1[++n1]=i;for(int i=1;i<=n;++i)if(s2[i])p2[++n2]=i;p1[n1+1]=p2[n1+1]=n+1;
    if(n1!=n2)return 0;
    if(m==0||m>n1){for(int i=1;i<=n;++i)if(s1[i]!=s2[i])return 0;return 1;}
    n=n1;
    if(m==n){
        if(p1[1]<p2[1])cz(1,1,p2[1]-p1[1]);else cz(1,0,p1[1]-p2[1]);
        for(int i=1;i<=m;++i)if(p1[i]!=p2[i])cz(1,0);
        for(int i=1;i<=m;++i)if(p1[i]!=p2[i])return 0;return 1;
    }
    if(m%2==0){
        int s1=0,s2=0;for(int i=1;i<=n+1;i+=2)s1+=p1[i]-p1[i-1],s2+=p2[i]-p2[i-1];
        if(s1!=s2)return 0;
    }
    int k=n-m,*p=p1;bool T=0;
    for(int i=1;i<=k;++i)cz(i,T,p[i]-p[i-1]-1);
    for(int i=k+1;i<=n;i+=2){
        cz(k+1,T,p[k+1]-p[k]-1);cz(k,T);
        if(i==n)i=k;
    }
//    bool ok=1;for(int i=1;i<=n;++i)ok&=p[i]==i;
//    assert(ok==m%2);
//    for(int i=1;i<=n;++i)printf("%d ",p[i]);puts("");
    if(m%2==0){
        for(int i=n;i>k;i-=2)cz(k,T,-(p[n]-p[n-1]-1)),cz(k+1,T);
    }
    
    p=p2,T=1;
    for(int i=1;i<=k;++i)cz(i,T,p[i]-p[i-1]-1);
    for(int i=k+1;i<=n;i+=2){
        cz(k+1,T,p[k+1]-p[k]-1);cz(k,T);
        if(i==n)i=k;
    }
    if(m%2==0){
        for(int i=n;i>k;i-=2)cz(k,T,-(p[n]-p[n-1]-1)),cz(k+1,T);
    }
    return 1;
}
int main(){
    int ca;scanf("%d",&ca);while(ca--){
        scanf("%d%d",&n,&m);scanf("%s%s",s1+1,s2+1);for(int i=1;i<=n;++i)s1[i]-='0',s2[i]-='0';
        if(!wk())puts("-1");else{printf("%d\n",m1+m2);for(int i=1;i<=m1;++i)printf("%d %d\n",a1[i][0],a1[i][1]);for(int i=m2;i;--i)printf("%d %d\n",a2[i][0],a2[i][1]);}
    }
    return 0;
}