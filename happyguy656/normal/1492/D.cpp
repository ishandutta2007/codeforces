#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define p1 putchar('1')
#define p0 putchar('0')
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=2e5+3;
int a,b,n,k;
int s1[mxn],s2[mxn];
int main(){
    scanf("%d%d%d",&a,&b,&k);
    if(k==0){
        puts("Yes");
        for(int i=1;i<=b;++i)p1;for(int i=1;i<=a;++i)p0;puts("");
        for(int i=1;i<=b;++i)p1;for(int i=1;i<=a;++i)p0;puts("");
        return 0;
    }
    --b;n=a+b;
    if(k>=n||!b||b==n)return puts("No"),0;
    s1[k+1]=1,s2[1]=1;
    --b;
    for(int i=1;i<=n&&b;++i)if(i!=1&&i!=k+1)--b,s1[i]=s2[i]=1;
    puts("Yes");
    p1;for(int i=n;i;--i)printf("%d",s1[i]);puts("");
    p1;for(int i=n;i;--i)printf("%d",s2[i]);puts("");
    return 0;
}