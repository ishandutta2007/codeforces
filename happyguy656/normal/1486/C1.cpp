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
inline int ask1(int a){return ask(a,a+1)==a?a+1:a;}
inline int gans(){
    int l=1,r=n,mid;
    int now=ask(1,n);
    while(l!=r){
        mid=(l+r)>>1;
        if(r-l==1)return ask1(l);
        if(r-l==2){
            if(now==l)return ask1(l+1);
            else if(now==r)return ask1(l);
            else return ask1(l)==l?l:r;
        }
        int x=ask(l,mid),y=ask(mid+1,r);
        if(now==x)r=mid,now=x;
        else if(now==y)l=mid+1,now=y;
        else if(now<=mid)l=mid+1,now=y;
        else r=mid,now=x;
    }
    return l;
}
int main(){
    srand((uu)time(0));
    scanf("%d",&n);
    printf("! %d\n",gans());
    return 0;
}