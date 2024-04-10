#include<bits/stdc++.h>
#pragma GCC target("avx2,bmi,bmi2,popcnt,lzcnt")
#pragma GCC optimize("O3,unroll-loops")
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
bitset<100005> b[10005];
vector<int> E[500005];
void solve(){
    srand(time(NULL));
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<int,vector<int> > > v;
    map<int,int> vval;
    map<int,int> cnt;
    for(int i = 0;i<n;i++){
        vector<int> tmp;
        for(int j = 0;j<m;j++){
            int x;
            scanf("%d",&x);
            tmp.pb(x);
            vval[x];
            cnt[x]++;
        }
        int w;
        scanf("%d",&w);
        v.pb(mp(w,tmp));
    }
    sort(v.begin(),v.end());
    int index=0;
    for(auto it:cnt){
        if(it.y>=50){
            vval[it.x]=++index;
        }
    }
    for(auto &it:vval){
        if(it.y==0)it.y=++index;
    }
    bitset<100005> mask;
    for(int i = 0;i<n;i++)mask[i]=1;
    for(int i = 0;i<n;i++){
        for(auto &it:v[i].y){
            it=vval[it];
            if(it<10000)b[it][i]=1;
            else
            E[it].pb(i);
        }
    }
    LL ans=1e18;
    for(int i = 0;i<n;i++){
        bitset<100005> tmp;
        for(auto &it:v[i].y){
            if(it<10000)tmp|=b[it];
            else for(auto it2:E[it])tmp[it2]=1;
        }
        if(tmp.count()!=n){
            tmp^=mask;
            ans=min(ans,v[tmp._Find_first()].x+v[i].x+0ll);
        }
    }
    if(ans==1e18)ans=-1;
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
    //scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}