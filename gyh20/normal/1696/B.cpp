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
        n=read(),ans=0;
        for(re int i=1;i<=n;++i)ans=max(ans,a[i]=read());
        if(ans==0)puts("0");
        else{
            re int L=1,R=n;
            while(!a[L])++L;
            while(!a[R])--R;
            while(a[L])++L;
            while(a[R])--R;
            if(L<=R)puts("2");
            else puts("1");
        }
    }
}