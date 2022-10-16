#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define forg(i,x) for(register int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf a1234=scanf
#define rint register int
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define ff fflush(stdout)
int a1234;
inline void xxx(){for(;;);}
inline int rd(int l,int r){return rand()%(r-l+1)+l;}
 
const int mxn=1e5+3;
int n;
inline int ask(int a,int b){
    int x;printf("? %d %d\n",a,b);ff;scanf("%d",&x);return x;
}
int main(){
    srand((uu)time(0));
    scanf("%d",&n);
    int p=ask(1,n);
    bool ok;
    if(p==1||p==n)ok=p==1;
    else ok=ask(p,n)==p;
    
    int l,r,mid;
    if(ok){
        l=p+1,r=n,mid;
        while(l<r){
            mid=(l+r)>>1;
            if(ask(p,mid)==p)r=mid;else l=mid+1;
        }
    }else{
        l=1,r=p-1,mid;
        while(l<r){
            mid=(l+r+1)>>1;
            if(ask(mid,p)==p)l=mid;else r=mid-1;
        }
    }
    printf("! %d\n",l);
    return 0;
}