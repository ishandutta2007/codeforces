#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int M=1000000007;
const int maxn=1e5+7;
vector<int> G[maxn];
int a[maxn],n,phi[maxn],cnt[maxn],r,ans,res;
void add(int &x,int y){x+=y;if(x>=M)x-=M;}
void sub(int &x,int y){x-=y;if(x<0) x+=M;}
void ins(int x){
    for (auto y:G[x]){
        add(res,cnt[y]);
        add(cnt[y],phi[y]);
    }
}
void del(int x){
    for (auto y:G[x]) sub(cnt[y],phi[y]);
}
int main(){
    for (int i=1;i<maxn;i++) phi[i]=i;
    for (int i=1;i<maxn;i++)
        for (int j=2;j*i<maxn;j++) phi[i*j]-=phi[i];
    for (int i=1;i<maxn;i++)
        for (int j=1;j*i<maxn;j++)
            G[i*j].pb(i);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++){
        res=0;
        for (int j=1;j*i<=n;j++) ins(a[i*j]);
        for (int j=1;j*i<=n;j++) del(a[i*j]);
        add(ans,1ll*res*phi[i]%M);
    }
    ans=ans*2%M;
    for (int i=1;i<=n;i++) add(ans,1ll*i*a[i]%M);
    printf("%d\n",ans);
}