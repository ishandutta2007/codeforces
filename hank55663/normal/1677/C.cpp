#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
int f[100005];
int Size[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[100005],b[100005];
    for(int i = 0;i<n;i++)scanf("%d",&a[i]);
    for(int i = 0;i<n;i++)scanf("%d",&b[i]);
    for(int i = 1;i<=n;i++)f[i]=i,Size[i]=1;
    for(int i = 0;i<n;i++){
        int x=Find(a[i]),y=Find(b[i]);
        if(x!=y){
            f[x]=y;
            Size[y]+=Size[x];
        }
    }
    int cnt=0;
    for(int i = 1;i<=n;i++){
        if(f[i]==i&&Size[i]&1==1){
            cnt++;
        }
    }
    n-=cnt;
    LL ans=n/2*1ll*2*(cnt+1);
    ans+=(n/2-1)*1ll*(n/2)*2;
    printf("%lld\n",ans);
}  
int main(){
   // srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}