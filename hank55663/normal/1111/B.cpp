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
int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    int a[100005];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    LL suf[100005];
    suf[n]=0;
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1]+a[i];
    }
    double ans=0;
    for(int i=0;i<=m&&i<n;i++){
        int len=n-i;
        LL sum=suf[i]+min((LL)k*(n-i),(LL)m-i);
       // printf("%lld %d\n",sum,len);
        ans=max(ans,(double)sum/len);
    }
    printf("%.12f\n",ans);
}
/*

i f f x f l b
*/