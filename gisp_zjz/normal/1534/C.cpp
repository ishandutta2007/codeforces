#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
const int M=1000000007;
int _,ans,n,a[maxn],b[maxn],p[maxn];
bool vis[maxn];

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n); ans=1;
        for (int i=1;i<=n;i++) {scanf("%d",&a[i]);p[a[i]]=i;vis[i]=0;}
        for (int i=1;i<=n;i++) scanf("%d",&b[i]);
        for (int i=1;i<=n;i++) if (!vis[i]){
            int t=i;
            do{
                vis[t]=1;
                t=p[b[t]];
            }while (t!=i);
            ans=ans*2%M;
        }
        printf("%d\n",ans);
    }
    return 0;
}