#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int num[100005];
    int n;
    scanf("%d",&n);
    int a[100005];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int vis[100005];
    MEM(vis);
    int cnt=0;
    for(int i=0;i<n;i++){
        if(!vis[a[i]])
            cnt++;
        vis[a[i]]=1;
        num[i]=cnt;
    }
    MEM(vis);
    LL ans=0;
    for(int i=n-1;i>0;i--){
        if(!vis[a[i]])
            ans+=num[i-1];
        vis[a[i]]=1;
    }
    printf("%lld\n",ans);
}