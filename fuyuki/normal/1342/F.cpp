#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=15,INF=0x3f3f3f3f;
int T,n,m,pos[N];
int a[N],s[1<<N],id[1<<N];
int f[N][1<<N],g[N][1<<N];
vector<int>fp[N][1<<N],gp[N][1<<N];
V input(){
    cin>>n,m=(1<<n)-1;
    FOR(i,0,n-1)cin>>s[1<<i],pos[i]=i+1;
    FOR(i,1,m)s[i]=s[i-1&i]+s[i&-i];
}
I cmp(int x,int y){return s[x]<s[y];}
I low(int x){return __builtin_ctz(x);}
I cmax(int&x,int y){return(x-y>>31)&&(x=y);}
V init(){
    FOR(i,0,m)FOR(j,0,n-1)f[j][i]=g[j][i]=-INF;
    FOR(i,1,m)id[i]=i;
    sort(id+1,id+m+1,cmp);
    for(int l=1,r;l<=m;l=r+1){
        for(r=l;r<m&&s[id[r+1]]==s[id[l]];r++);
        FOR(i,l,r)g[low(id[i])][id[i]]=1;
        FOR(i,l,r)for(int x=id[i],k;(x=++x|id[i])<=m;)
            FOR(j,0,n-1)if(((x^id[i])>>j&1)&&(id[i]>>j))
                if(cmax(g[k=low(id[i]>>j)+j][x],f[j][x^id[i]]+1))
                    gp[k][x]=fp[j][x^id[i]],gp[k][x].push_back(id[i]<<4|k);
        FOR(i,l,r)for(int x=id[i];(x=++x|id[i])<=m;)FOR(j,0,n-1)
            if((id[i]>>j&1)&&cmax(f[j][x],g[j][x]))fp[j][x]=gp[j][x];
        FOR(i,l,r)if(cmax(f[low(id[i])][id[i]],1))
            fp[low(id[i])][id[i]]=vector<int>{id[i]<<4|low(id[i])};
    }
}
V del(int x){while(++x<n)pos[x]--;}
V solve(int x,int p){
    FOR(i,0,n-1)if((x>>i&1)&&i!=p)
        cout<<pos[i]<<' '<<pos[p]<<'\n',del(i);
}
V work(){
    int ans=0,p=0;
    FOR(i,0,n-1)if(f[i][m]>ans)ans=f[i][m],p=i;
    cout<<n-ans<<'\n';
    for(int x:fp[p][m])solve(x>>4,x&15);
}
int main(){
    cin.tie(0),cin>>T;
    while(T--)input(),init(),work();
    return 0;
}