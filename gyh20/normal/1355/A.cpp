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
int n,m,t,ans;
inline int mn(re int x){
    re int ans=10;
    while(x){
        ans=min(ans,x%10);
        x/=10;
    }
    return ans;
}
inline int mx(re int x){
    re int ans=0;
    while(x){
        ans=max(ans,x%10);
        x/=10;
    }
    return ans;
}
signed main(){
    t=read();
    while(t--){
        n=read(),m=read()-1;
        while(m--){
            re int x=mn(n),y=mx(n);
            if(!x)break;
            n+=x*y;
        }
        printf("%lld\n",n);
    }
}