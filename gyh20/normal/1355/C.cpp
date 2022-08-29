#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
int n,m,t,ans,a,b,c,d,x,y;
signed main(){
    a=read();b=read();c=read();d=read();
    for(re int i=1;i<=1e6;++i){
        x=i-c;y=i-b;x=max(x,a);y=min(y,b);//x,y
        x=y-x+1;
        if(x<=0)continue;//
        y=min(i-1,d)-c+1;//z
        if(y<=0)continue;//
        ans+=x*y;
    }
    printf("%lld\n",ans);
}