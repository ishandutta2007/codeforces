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
int n,a[mxn];
inline void ask(int x){
    if(a[x]||x<1||x>n)return;
    printf("? %d\n",x);
    fflush(stdout);
    scanf("%d",a+x);
}

int main(){
    scanf("%d",&n);
    if(n==1)return puts("! 1"),ff,0;
    ask(1),ask(2),ask(n-1),ask(n);
    if(a[1]<a[2])return puts("! 1"),ff,0;
    if(a[n]<a[n-1])return printf("! %d\n",n),ff,0;
    int l=1,r=n,mid;
    while(l<r){
        mid=(l+r)>>1;
        ask(mid-1),ask(mid),ask(mid+1);
        if(a[mid]<a[mid-1]&&a[mid]<a[mid+1])return printf("! %d\n",mid),ff,0;
        if(a[mid]>a[mid-1])r=mid+1;else l=mid-1;
    }
    return 0;
}