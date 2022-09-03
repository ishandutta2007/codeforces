#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
#define MXN 3000
int f[100005];
int pval[100005];
LL mod=1e9+7;
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
LL f_pow(LL a,LL b){
    LL res = 1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
//int mod=1e9+7;
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 1;i<=n;i++)
    f[i]=i;
    for(int i = 0;i<n-1;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        if(c==0){
            f[Find(x)]=Find(y);
        }
    }
    for(int i = 1;i<=n;i++){
        pval[Find(i)]++;
    }
    vector<int> v;
    for(int i = 1;i<=n;i++){
        if(Find(i)==i)
        v.pb(pval[i]);
    }
    LL pown[100005];
    pown[0]=1;
    for(int i = 1;i<=n;i++)
    pown[i]=pown[i-1]*n%mod;
    LL ans = f_pow(n,k);
    for(auto it:v){
    //    printf("%d\n",it);
        ans -= f_pow(it,k);
        ans = (ans%mod+mod)%mod;
    }
    printf("%lld\n",ans);
}