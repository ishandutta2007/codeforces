#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
int n,m,a[1000002],b[1000002],t,ans;
int main(){
    t=read();
    while(t--){
        n=read(),m=read(),ans=0;
        for(re int i=1;i<=n;++i)ans=max(ans,read()|m);
        printf("%d\n",ans);
    }
}