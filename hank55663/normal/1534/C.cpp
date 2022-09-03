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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define last Last
#define MXN 200005
const int mod=1e9+7;
int f[400005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int rev=(mod+1)/2;
void solve(){
    int n;
    scanf("%d",&n);
    int a[2][400005];
    for(int i = 1;i<=n;i++)f[i]=i;
    for(int j = 0;j<2;j++)
    for(int i = 0;i<n;i++){
        scanf("%d",&a[j][i]);
    }
    for(int i = 0;i<n;i++){
        int x=a[0][i],y=a[1][i];
        int fx=Find(x),fy=Find(y);
        f[fx]=fy;
    }
    LL ans=1;
    for(int i = 1;i<=n;i++){
        if(f[i]==i)ans*=2,ans%=mod;
    }
    for(int i = 0;i<n;i++){
        if(a[0][i]==a[1][i]){
            ans=ans*rev%mod;
        }
    }
    printf("%lld\n",ans);
}
/*
void solve(){
    int n;
    scanf("%d",&n);
    int a[400005];
    a[0]=a[n+1]=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    LL ans=0;
    for(int i = 1;i<=n;i++){
        if(a[i]>a[i-1]&&a[i]>a[i+1]){
            int Max=max(a[i-1],a[i+1]);
            ans+=a[i]-Max;
            a[i]=Max;
        }
    }
    for(int i = 1;i<=n+1;i++){
        ans+=abs(a[i]-a[i-1]);
    }
    printf("%lld\n",ans);
}
*/
/*
ax+by<=c;
bx+ay<=d;
*/
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--)
        solve();
}
/*
2 3 5 6 1 4
*/