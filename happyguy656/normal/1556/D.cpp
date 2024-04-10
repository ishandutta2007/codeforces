#include<bits/stdc++.h>
using namespace std;
#define forg(i,x) for(int i=fir[x];i;i=nxt[i])
#define uu unsigned
#define scanf abc=scanf
#define fre(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;
typedef uu long long ull;
typedef pair<int,int>pii;
int abc;
inline int rd(int l,int r){return rand()%(r-l+1)+l;}

const int mxn=1e4+3;
int n,m,v1,v2,v3,v4,v5,v6,a[mxn],b[mxn]={0,1,6,4,2,3,5,4};
int ask(int tp,int x,int y){if(!tp)printf("and %d %d\n",x,y);else printf("or %d %d\n",x,y);/*if(tp)return b[x]|b[y];else return b[x]&b[y];*/fflush(stdout);cin>>x;return x;}
int as(int x,int y){return ask(0,x,y)^ask(1,x,y);}
int main(){
    cin>>n>>m;
    v1=ask(0,1,2),v2=ask(1,1,2),v3=ask(0,1,3),v4=ask(1,1,3),v5=ask(0,2,3),v6=ask(1,2,3);
    for(int i=30;~i;--i){
        int t=-1,n1=v1>>i&1,n2=v2>>i&1,n3=v3>>i&1,n4=v4>>i&1,n5=v5>>i&1,n6=v6>>i&1;
        if(n1==n2)t=n1,a[1]|=t<<i,a[2]|=t<<i,a[3]|=(n3^n4^t)<<i;
        else if(n3==n4)t=n3,a[1]|=t<<i,a[3]|=t<<i,a[2]|=(n1^n2^t)<<i;
        else if(n5==n6)t=n5,a[2]|=t<<i,a[3]|=t<<i,a[1]|=(n1^n2^t)<<i;
    }
    for(int i=4;i<=n;++i)a[i]=a[1]^as(1,i);
    sort(a+1,a+n+1);printf("finish %d\n",a[m]);
    return 0;
}