#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
int mod=998244353;
LL ans[1000005];
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pair<int,pii> > v;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int x;
            scanf("%d",&x);
            v.pb(mp(x,mp(i,j)));
        }
    }
    sort(v.begin(),v.end());
    int l=0;
    LL now=0;
    LL sumx=0;
    LL sumy=0;
    LL sum2=0;
    int rr,cc;
    scanf("%d %d",&rr,&cc);
    for(int i=0;i<v.size();i++){
        if(v[i].x==v[0].x){
            if(v[i].y.x==rr&&v[i].y.y==cc){
                printf("%d\n",ans[i]);
                continue;
            }
            continue;
        }
        while(v[i].x>v[l].x){
            sum2+=sqr((LL)v[l].y.y)+sqr((LL)v[l].y.x);
            sum2%=mod;
            sumx+=v[l].y.x;
            sumx%=mod;
            sumy+=v[l].y.y;
            sumy%=mod;
            now+=ans[l];
            now%=mod;
            l++;
        }
       // printf("%d %d %d %d\n",now,sumx,sumy,sum2);
        ans[i]=now+(sqr((LL)v[i].y.x)+sqr((LL)v[i].y.y))*l-2ll*v[i].y.x*sumx-2ll*v[i].y.y*sumy+sum2;
        ans[i]=(ans[i]%mod+mod)%mod*f_pow(l,mod-2)%mod;
        if(v[i].y.x==rr&&v[i].y.y==cc){
            printf("%d\n",ans[i]);
            continue;
        }
       // printf("%d\n",ans[i]);
    }
}