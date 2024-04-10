#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
LL mod;
LL mod2;
vector<int> v[500005];
LL myrand(){
    return ((rand()*1ll)<<30)+rand();
}
void init(){
    mod=myrand()%1000000000000000ll+1000000000000000;
    while(true){
        int ok=1;
        for(LL i=2;i*i<=mod;i++){
            if(mod%i==0){
                ok=0;
                break;
            }
        }
        if(ok)break;
        mod++;
    }
    mod2=myrand()%1000000000000000ll+1000000000000000;
    while(true){
        int ok=1;
        for(LL i=2;i*i<=mod2;i++){
            if(mod2%i==0){
                ok=0;
                break;
            }
        }
        if(ok)break;
        mod2++;
    }
}    
LL val[2][500005];
LL cnt[500005];
pll pre[500005];
void solve(){
    srand(time(NULL));
    init();
    int n;
    scanf("%d",&n);

    for(int i = 1;i<=n;i++){
        val[0][i]=myrand();
        val[1][i]=myrand();
    }

    fill(cnt,cnt+500005,0);
    map<pll,int> m;

    pre[0]=mp(0,0);
    int l=0;
    m[pre[0]]++;
    LL ans=0;
    LL now=0,now2=0;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(cnt[x]==2){
            now-=val[0][x]*2;
            now2-=val[1][x]*2;
            cnt[x]=0;
        }
        else{
            cnt[x]++;
            now+=val[0][x];
            now2+=val[1][x];
        }
        if(v[x].size()>=3){
            int ll=v[x][v[x].size()-3];
            while(l<ll){
                m[pre[l]]--;
               // printf("r %d\n",pre[l]);
                l++;
            }
        }
        v[x].pb(i);
        pre[i]=mp(now,now2);
        ans+=m[pre[i]];
        m[pre[i]]++;
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}