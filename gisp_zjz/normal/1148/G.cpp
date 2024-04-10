#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+3;
const int N=1e5+3;
const int E=10;
int l[maxn],b[maxn],mu[maxn],t;
int prime[maxn/5];
vector <int> f[N],g[N];
int a[N],pp[N],ans[N],n,k,tot,cnt;
bool p[maxn];
mt19937_64 gen(time(0));
void prime_sieve(){
    p[1]=1; mu[1]=1; t=0; cnt=0;
    for (int i=2;i<maxn;i++){
        if (!p[i]) prime[++t]=i,mu[i]=-1,l[i]=i;
        for (int j=1;j<=t;j++){
            if (1ll*prime[j]*i>=maxn) break;
            p[prime[j]*i]=1;
            l[prime[j]*i]=prime[j];
            mu[i*prime[j]]=i%prime[j]?-mu[i]:0;
            if (i%prime[j]==0) break;
        }
    }
}
int calc(int x){
    int ret=0;
    for (auto v:f[x]) ret+=b[v];
    for (auto v:g[x]) ret+=b[v];
    return ret;
}
void add(int x){
    //cout<<x<<endl;
    //for (auto v:f[x])cout<<v<<' ';cout<<endl;
    //for (auto v:g[x])cout<<v<<' ';cout<<endl;
    for (auto v:f[x]) b[v]++;
    for (auto v:g[x]) b[v]--;
}
void sub(int x){
    //cout<<x<<endl;
    //for (auto v:f[x])cout<<v<<' ';cout<<endl;
    //for (auto v:g[x])cout<<v<<' ';cout<<endl;
    for (auto v:f[x]) b[v]--;
    for (auto v:g[x]) b[v]++;
}
void dfs(int id,int x,int y){
    if (y==1){
        if (mu[x]==1) f[id].push_back(x);
        else g[id].push_back(x);
        return;
    }
    int h=l[y];
    while (y%h==0) y/=h;
    dfs(id,x,y);
    dfs(id,x*h,y);
}
int main(){
    prime_sieve();
    //for (int i=1;i<=20;i++)cout<<i<<' '<<l[i]<<endl;
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        dfs(i,1,a[i]);
    }
    for (int i=1;i<=n;i++) pp[i]=i;
    for (int temp=0;temp<E;temp++){
        random_shuffle(pp+1,pp+1+n);
        tot=0;
        //memset(b,0,sizeof(b));
        for (int i=1;i<=n;i++){
            if (!calc(pp[i])) ans[++tot]=pp[i],add(pp[i]);
            if (tot==k) break;
        }
        if (tot==k){
            //for (int i=1;i<=n;i++)cout<<a[pp[i]]<<' ';cout<<endl;
            sort(ans+1,ans+1+k);
            for (int i=1;i<=k;i++) printf("%d ",ans[i]); puts("");
            return 0;
        }
        for (int i=1;i<=tot;i++) sub(ans[i]);
    }
    while (true){
        random_shuffle(pp+1,pp+1+n);
        tot=0;
        memset(b,0,sizeof(b));
        ans[++tot]=pp[1]; add(pp[1]);
        for (int i=2;i<=n;i++){
            if (calc(pp[i])) ans[++tot]=pp[i],add(pp[i]);
            if (tot==k) break;
        }
        if (tot==k){
            sort(ans+1,ans+1+k);
            for (int i=1;i<=k;i++) printf("%d ",ans[i]); puts("");
            return 0;
        }
        for (int i=1;i<=tot;i++) sub(ans[i]);
    }
}