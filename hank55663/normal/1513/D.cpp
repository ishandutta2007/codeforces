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
const int mod=1e9+7;
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
void solve(){
    int n,p;
    scanf("%d %d",&n,&p);
    int a[200005];
    vector<pii> v;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        v.pb(mp(a[i],i));
    }
    sort(v.begin(),v.end());
    int vis[200005];
    fill(vis,vis+n,0);
    vector<pair<int,pii> > edge;
    for(auto it:v){
        for(int j = it.y;j<n;j++){
            if(__gcd(it.x,a[j])!=it.x)break;
            else{
                edge.pb(mp(it.x,mp(it.y,j)));
            }
            if(vis[j])break;
            vis[j]=1;
        }
    }
    fill(vis,vis+n,0);
    for(auto it:v){
        for(int j =it.y;j>=0;j--){
            if(__gcd(it.x,a[j])!=it.x)break;
            else{
                edge.pb(mp(it.x,mp(it.y,j)));
            }
            if(vis[j])break;
            vis[j]=1;
        }
    }
    sort(edge.begin(),edge.end());
    for(int i = 0;i<n;i++)f[i]=i;
    int cnt=n-1;
    LL ans=0;
    for(auto it:edge){
     
        int a=Find(it.y.x),b=Find(it.y.y);
        if(it.x>p)break;
        if(a!=b){
               //printf("%d %d %d\n",it.x,it.y.x,it.y.y);
            ans+=it.x;
            cnt--;
            f[a]=b;
        }
    }
    ans+=cnt*1ll*p;
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}