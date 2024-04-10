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
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
typedef long long LL;
int main(){
    int t;
    scanf("%d",&t);
    vector<LL> v;
    for(LL i=2;i<=1000000;i++){
        LL k=i*i;
        LL x=sqrt(i)+1e-6;
        if(x*x==i)
        continue;
        for(int j=3;;j++){
            LL ori=k;
            k*=i;
            if(k/i!=ori||k%i!=0||k>1e18||k<ori)
            break;
            if(j&1)
            v.pb(k);
        }
    }
    sort(v.begin(),v.end());
    vector<LL> vv;
    vv.pb(v[0]);
    for(int i=1;i<v.size();i++){
        if(v[i]!=v[i-1])
        vv.pb(v[i]);
    }
    while(t--){
        LL n;
        scanf("%lld",&n);
        LL ans=n;
        LL Max=1e9+1,Min=1;
        while(Max>Min+1){
            LL mid=(Max+Min)/2;
            if(mid*mid>n){
                Max=mid;
            }
            else{
                Min=mid;
            }
        }
        ans-=Min;
        ans-=upper_bound(vv.begin(),vv.end(),n)-vv.begin();
        printf("%lld\n",ans);
    }
    return 0;
}