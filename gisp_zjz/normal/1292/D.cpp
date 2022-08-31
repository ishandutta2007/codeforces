#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=5005;
const int N=5000;
int cnt[maxn],n,f[maxn],p[maxn],lca[maxn][maxn],cc[maxn];
vector <int> h[maxn];
ll ans,res;
int dis(int x,int y){
    if (x>y) swap(x,y);
    return f[x]+f[y]-lca[x][y]*2;
}

int main(){
    for (int i=2;i<maxn;i++){
        int j=2,r=i;
        while (j*j<=r){
            while (r%j==0) h[i].pb(j),f[i]++,r/=j;
            ++j;
        }
        if (r>1) h[i].pb(r),f[i]++;
    }
    for (int i=1;i<maxn;i++) f[i]+=f[i-1];
    for (int i=1;i<=N;i++) lca[i][i]=f[i];
    for (int i=2;i<=N;i++){
        int large=h[i][h[i].size()-1];
        for (int j=large;j<=N;j++) lca[i-1][i]+=cc[j];
        for (auto fac:h[i]) cc[fac]++;
    }
    for (int i=1;i<=N;i++)
        for (int j=i+2;j<=N;j++)
            lca[i][j]=min(lca[i][j-1],lca[j-1][j]);
    scanf("%d",&n);
    for (int i=1;i<=n;i++){
        int x;scanf("%d",&x);
        if (!x) ++x;
        cnt[x]++;
    }
    ans=9e18;
    for (int i=1;i<=N;i++){
        res=0;
        for (int j=1;j<=N;j++) {
            res+=1ll*cnt[j]*dis(i,j);
        }
        ans=min(ans,res);
    }
    cout << ans << endl;
}