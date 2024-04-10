#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
    re int t=0,f=0;re char v=getchar();
    while(v<'0')f|=(v=='-'),v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return f?-t:t;
}
int n,a[100002],b[100002],m,t,v0,v1;
int main(){
    t=read();
    while(t--){
        n=read();v0=v1=0;
        bool ia=0;
        for(re int i=1;i<=n;++i)a[i]=read();
        for(re int i=1;i<=n;++i)b[i]=read();
        for(re int i=1;i<=n;++i){
            if(a[i]==b[i]){if(a[i]==-1)v0=1;if(a[i]==1)v1=1;}
            else if(a[i]>b[i]&&v0){if(a[i]==-1)v0=1;if(a[i]==1)v1=1;}
            else if(a[i]<b[i]&&v1){if(a[i]==-1)v0=1;if(a[i]==1)v1=1;}
            else{
                ia=1;puts("NO");break;
            }
        }
        if(!ia)puts("YES");
    }
}