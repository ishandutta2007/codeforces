#include<bits/stdc++.h>
#define re register
#define int long long
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
} 
using namespace std;
int n,m,a,b,c,d,t,ans,lim,x,y,xx,yy;
signed main(){
    t=read();
    while(t--){
        n=read(),m=read(),a=read(),b=read(),c=read();d=read();
        if(a>c)swap(a,c),swap(b,d);
        if(a==c&&b<d)swap(b,d);
        if(b>d){
            m-=(d-c)*n;b-=d-c;c=a;d=c;
        }
        else if(b>c){
            m-=(b-c)*n;d-=b-c;
            b=c;
        }
    //  printf("%lld %lld %lld %lld %lld\n",m,a,b,c,d);
        if(m<=0){
            puts("0");
            continue;
        }
        x=max(c,a)-min(a,c)+max(b,d)-min(b,d);
        y=max(b,d)-min(a,c);
    //  printf("%lld %lld\n",x,y);
        if(y){
        xx=m%y,yy=m/y;
        yy=min(yy,n);xx=m-yy*y;
        ans=min(yy?x*yy+xx*2:1000000000000000000ll,(yy<n&&xx<y)?x*(yy+1)-(y-xx):100000000000000000ll);}else ans=m*2;
        printf("%lld\n",ans);
    }
}