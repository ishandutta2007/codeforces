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
int main(){
    map<int,vector<int> > m;
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i=0;i<n;i++){ 
        scanf("%d",&a[i]);
        m[a[i]].pb(i);
    }
    vector<pii> v;
    for(auto it:m){
        v.pb(mp(it.y[0],1));
        v.pb(mp(it.y.back()+1,-1));
    }
    int sum=0;
    int now=0;
    sort(v.begin(),v.end());
    int index=0;
    for(int i=0;i<n;i++){
        while(v[index].x==i){
            now+=v[index].y;
            index++;
            if(now==0)
            sum++;
        }
    }
    int mod=998244353;
    LL ans=1;
    for(int i=0;i<sum;i++){
        ans=ans*2%mod;
    }
    printf("%lld\n",ans);
}