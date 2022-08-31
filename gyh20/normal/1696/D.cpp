#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
    re int t=0;re char v=getchar();
    while(v<'0')v=getchar();
    while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
    return t;
}
int t,n,a[500002],pos[500002],pmn[500002],pmx[500002],smn[500002],smx[500002];
inline int solve1(re int x){
    if(x==1)return 0;
    return (pmx[x]==a[x]?solve1(pos[pmn[x]]):solve1(pos[pmx[x]]))+1;
}
inline int solve2(re int x){
    if(x==n)return 0;
    return (smx[x]==a[x]?solve2(pos[smn[x]]):solve2(pos[smx[x]]))+1;
}
int main(){
    t=read();
    while(t--){
        n=read();
        for(re int i=1;i<=n;++i)a[i]=read(),pos[a[i]]=i;if(n==1){puts("0");continue;}
        pmn[1]=pmx[1]=a[1];for(re int i=2;i<=n;++i)pmn[i]=min(a[i],pmn[i-1]),pmx[i]=max(a[i],pmx[i-1]);
        smn[n]=smx[n]=a[n];for(re int i=n-1;i;--i)smx[i]=max(a[i],smx[i+1]),smn[i]=min(a[i],smn[i+1]);
        if(1ll*pos[n]*pos[1]==n&&pos[1]+pos[n]==n+1)puts("1");
        else if(pos[n]>1&&pos[n]<n)printf("%d\n",solve1(pos[n])+solve2(pos[n]));
        else printf("%d\n",solve1(pos[1])+solve2(pos[1]));
    }
}