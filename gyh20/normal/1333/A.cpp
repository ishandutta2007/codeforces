#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
int n,a,b,m,t;
int main(){
    t=read();
    while(t--){
        n=read();m=read();
        for(re int i=1;i<=n;++i){
            for(re int j=1;j<=m;++j){
                if(j==1&&i!=n)putchar('W');
                else putchar('B');
            }puts("");
        }
    }
}