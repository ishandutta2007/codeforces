#include<bits/stdc++.h>
using namespace std;
#define re register
#define int long long
inline int read(){
    re int t=0,f=0;re char v=getchar();
    while(v<'0')f|=(v=='-'),v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return f?-t:t;
}
int n,a[200002],b[200002],m,t,sum,x,ans[200002];
map<int,int>v;
signed main(){
    n=read();
    for(re int i=1;i<=n;++i)a[i]=read();
    for(re int i=1;i<=n;++i){
        v[b[i-1]]=i;
        b[i]=b[i-1]+a[i];
        ans[v[b[i]]]=i;
}ans[n+1]=1e9;
    for(re int i=n;i;--i){
    //  if(a[i]==0)ans[i]=i;
        if(!ans[i])ans[i]=n+1;
        ans[i]=min(ans[i],ans[i+1]);
        sum+=ans[i]-i;
    }
    printf("%lld",sum);
}