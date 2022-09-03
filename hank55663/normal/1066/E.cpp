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
int mod=998244353;
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
    int n,m;
    scanf("%d %d",&n,&m);
    char a[200005],b[200005];
    MEM(a),MEM(b);
    scanf("%s %s",a,b);
    reverse(a,a+n);
    reverse(b,b+m);
    int cnt=0;
    LL ans=0;
    for(int i=max(n,m)-1;i>=0;i--){
        if(b[i]=='1')
        cnt++;
        if(a[i]=='1')
        {
            ans=(ans+cnt*f_pow(2,i))%mod;
        }
    }
    printf("%lld\n",ans);
}