#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+10;
const int M=998244353;
int _,n,k,a[505],b[505],ans;
bool vis[505];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%d",&n,&k);
        memset(vis,0,sizeof(vis));
        for (int i=1;i<=k;i++){
            scanf("%d%d",&a[i],&b[i]);
            if (a[i]>b[i]) swap(a[i],b[i]);
            vis[a[i]]=vis[b[i]]=1;
        }
        int p=1;
        for (int i=k+1;i<=n;i++){
            while (vis[p]) ++p;
            a[i]=p; vis[p]=1;
        }
        for (int i=k+1;i<=n;i++){
            while (vis[p]) ++p;
            b[i]=p; vis[p]=1;
        }
        ans=0;
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                if (a[i]<a[j]&&a[j]<b[i]&&b[i]<b[j]) ++ans;
        printf("%d\n",ans);
    }
    return 0;
}