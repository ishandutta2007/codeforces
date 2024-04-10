#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
vector<int> factor[200005];
vector<pair<int,pii> > v[200005];
int val[200005],cnt[200005];
const int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
void dfs(int x,int f){
    for(auto it:v[x]){
        if(it.x!=f){
            for(auto it:factor[it.y.y]){
                cnt[it]--;
            }
            for(auto it:factor[it.y.x]){
                cnt[it]++;
                val[it]=max(cnt[it],val[it]);
            }
            dfs(it.x,x);
            for(auto it:factor[it.y.x]){
                cnt[it]--;
                //cnt[it]=max(cnt[it],val[it]);
            }
            for(auto it:factor[it.y.y]){
                cnt[it]++;
            }
            
        }
    }
}
LL ans=0;
void dfs2(int x,int f,LL sum){
    ans+=sum;
    ans%=mod;
    for(auto it:v[x]){
        if(it.x!=f){
            dfs2(it.x,x,sum*it.y.y%mod*f_pow(it.y.x,mod-2)%mod);
        }
    }
}
void solve(){
    ans=0;
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int a,b,x,y;
        scanf("%d %d %d %d",&a,&b,&x,&y);
        int gcd=__gcd(x,y);
        x/=gcd;
        y/=gcd;
        v[a].pb(mp(b,mp(x,y)));
        v[b].pb(mp(a,mp(y,x)));
    }
    fill(val,val+n+1,0);
    dfs(1,0);
    LL sum=1;
    for(int i =1;i<=n;i++){
       // printf("%d %d\n",i,val[i]);
        sum=sum*f_pow(i,val[i])%mod;
    }
    dfs2(1,0,sum);
    printf("%lld\n",ans);
}


int main(){
    for(int i=2;i<=200000;i++){
        if(factor[i].empty())
        for(int j = i;j<=200000;j+=i){
            int tmp=j;
            while(tmp%i==0){
                factor[j].pb(i);
                tmp/=i;
            }
        }
    }
    int t=1;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/