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
#define MXN 10000
vector<pii> v[500005];
int f[500005];
int Size[500005];
int Find(int x){
    if(f[x]==x)return x;
    return Find(f[x]);
}
vector<pii> vv;
void Union(int x,int y){
    int a=Find(x),b=Find(y);
    if(Size[a]>Size[b])swap(a,b);
    f[a]=b;
    Size[b]+=Size[a];
    vv.pb(mp(a,b));
}
void rm(){
    pii p=vv.back();
    vv.pop_back();
    f[p.x]=p.x;
    Size[p.y]-=Size[p.x];
}
LL ans=0;
void dc(int l,int r){
    if(l==r){
        for(auto it:v[l]){
            int a=Find(it.x),b=Find(it.y);
            ans+=Size[a]*1ll*Size[b];
        }
        return ;
    }
    int mid=(l+r)/2;
    for(int j = mid+1;j<=r;j++){
        for(auto it:v[j]){
            Union(it.x,it.y);
        }
    }
    dc(l,mid);
    for(int j = mid+1;j<=r;j++){
        for(auto it:v[j]){
           rm();
        }
    }
    for(int j  =l;j<=mid;j++){
        for(auto it:v[j]){
            Union(it.x,it.y);
        }
    }
    dc(mid+1,r);
    for(int j = l;j<=mid;j++){
        for(auto it:v[j]){
           rm();
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y,u;
        scanf("%d %d %d",&x,&y,&u);
        v[u].pb(mp(x,y));
    }
    for(int i = 1;i<=n;i++)f[i]=i,Size[i]=1;
    dc(1,n);
    printf("%lld\n",ans);
}
int main(){
   // srand(time(NULL));
    int t=1;;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}