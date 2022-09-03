
#pragma GCC optimize("Ofast") 
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
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int mod=1e9+7;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int cnt[100005][2];
    char c[100005];
    scanf("%s",c+1);
    MEM(cnt);
    for(int i=1;i<=n;i++){
        cnt[i][0]=cnt[i-1][0];
        cnt[i][1]=cnt[i-1][1];
        cnt[i][c[i]-'0']++;
    }
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        int one=cnt[r][1]-cnt[l-1][1];
        int zero=cnt[r][0]-cnt[l-1][0];
        LL ans=(f_pow(2,one)-1)*f_pow(2,zero)%mod;
        printf("%lld\n",ans);
    }
}