#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int mod=998244353;
LL f_pow(int a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n;
    int p[200005];
    int vis[200005];
    MEM(vis);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&p[i]);
        if(p[i]!=-1)
        vis[p[i]]=1;
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(!vis[i])
        v.pb(i);
    }
    set_t t;
    LL ans2=0;
    for(int i=n;i>=1;i--){
        if(p[i]!=-1){
            t.insert(p[i]);
            ans2+=t.order_of_key(p[i]);
            ans2%=mod;
        }
    }
    if(v.empty()){
        printf("%lld\n",ans2);
        return 0;
    }
    LL ans=0;
    LL cnt=0;
    LL pro=1;
    for(int i=1;i<v.size();i++)
    pro=pro*i%mod;
    for(int i=1;i<=n;i++){
        if(p[i]==-1){
            ans+=cnt*pro%mod;
            ans%=mod;
        }
        else{
            cnt+=lower_bound(v.begin(),v.end(),p[i])-v.begin();
            cnt%=mod;
        }
    }
    cnt=0;
    for(int i=n;i>=1;i--){
        if(p[i]==-1){
            ans+=cnt*pro%mod;
            ans%=mod;
        }
        else{
            cnt+=v.end()-lower_bound(v.begin(),v.end(),p[i]);
            cnt%=mod;
        }
    }
    LL nn=v.size();
    LL pai=nn*(nn-1)/2%mod;
    pai=pai*pai%mod;
    pro=1;
    for(int i=1;i<v.size()-1;i++)
    pro=pro*i%mod;
    pai=pai*pro%mod;
    if(v.size()!=1)
    for(int i=v.size()-1;i<=v.size();i++){
        pro=pro*i%mod;
    }

    ans2=ans2%mod*pro%mod;
    ans=(ans+pai+ans2)%mod;
  //  printf("%lld %lld %lld\n",ans,pai,ans2);
    if(v.size()==1){
        printf("%lld\n",ans);
    }
    else{
        printf("%lld\n",ans*f_pow(pro,mod-2)%mod);
    }
}