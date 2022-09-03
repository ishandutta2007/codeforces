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
    int n;
    scanf("%d",&n);
    int a[300005];
    LL sum=0;
    set<LL> s;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
        s.insert(sum);
    }
    int m;
    scanf("%d",&m);
    int b[300005];
    sum=0;
    LL ans=0;
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
        sum+=b[i];
        if(s.find(sum)!=s.end())
        ans++;
    }
    if(*s.rbegin()!=sum)
    printf("-1\n");
    else
    printf("%lld\n",ans);
    return 0;
}