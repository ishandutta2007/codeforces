#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+12;
int a[maxn],dp[maxn],b[maxn],_,n,ans,R[maxn];
vector<int>bb[maxn];
struct pa {
    int v,x;
}q[maxn];
#define pb push_back
struct sbwcy {
    int b[maxn];
    inline void upd(int x,int y){
        while (x<=n) b[x]=max(b[x],y),x+=x&(-x);
    }
    inline int qry(int x){
        int ret=-1000000000;
        while (x) ret=max(ret,b[x]),x-=x&(-x);
        return ret;
    }
}A,B;
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n+1;i++) bb[i].clear(),A.b[i]=B.b[i]=-1000000000;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=1,r=0;
        q[++r]=pa{n+1,n+1};
        for (int i=n;i;i--) {
            while (r>=l){
               if (q[r].v<a[i]) r--;
               else break;
            }
            R[i]=q[r].x;
            q[++r]=pa{a[i],i};
        }
        for (int i=1;i<=n;i++) bb[R[i]].pb(i);
        for (int i=1;i<=n;i++) dp[i]=b[i]=0; ans=0;
        int ma=a[1];
        dp[1]=1;
        for (int i=2;i<=n;i++){
            dp[i]=1;
            if (a[i]<=ma) dp[i]=2;
            ma=max(ma,a[i]);
            if (a[i]>=a[i-1]) dp[i]=max(dp[i],dp[i-1]+1);
            dp[i]=max(dp[i],A.qry(a[i])+1);
            dp[i]=max(dp[i],B.qry(a[i])+2);
            A.upd(a[i-1],dp[i-1]);

            for (auto p:bb[i]) B.upd(a[p],dp[p]);
        }
        for (int i=1;i<n;i++) ans=max(ans,dp[i]);
        ans=max(ans,dp[n]);
        printf("%d\n",ans);
    }
    return 0;
}