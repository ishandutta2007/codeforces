#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=3e5+7;
int x[2005],y[2005],z[2005];
bool vis[2005];
int n,m;

int main(){
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d%d%d",&x[i],&y[i],&z[i]);
    for (int i=1;i<=n;i++) if (!vis[i]){
        int pos=-1,mn=0;
        for (int j=1;j<=n;j++) if (!vis[j]&&j!=i){
            int dis=abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j]);
            if (pos==-1||mn>dis) pos=j,mn=dis;
        }
        printf("%d %d\n",i,pos);
        vis[pos]=1; vis[i]=1;
    }
    return 0;
}