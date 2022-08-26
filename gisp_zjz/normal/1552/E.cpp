#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int maxn=5e5+10;
const int M=998244353;
bool vis[105];
int a[10005],n,k,last[105],x[105],y[105];
int main(){
    scanf("%d%d",&n,&k);
    for (int i=1;i<=n*k;i++) scanf("%d",&a[i]);
    int d=(n+k-2)/(k-1),now=0;
    for (int i=1;i<=n*k;i++){
        if (vis[a[i]]) continue;
        if (!last[a[i]]) last[a[i]]=i;
        else{
            x[a[i]]=last[a[i]]; y[a[i]]=i;
            vis[a[i]]=1; now++;
        }
        if (now==d){now=0; for (int j=1;j<=n;j++) last[j]=0;}
    }
    for (int i=1;i<=n;i++) printf("%d %d\n",x[i],y[i]);
}