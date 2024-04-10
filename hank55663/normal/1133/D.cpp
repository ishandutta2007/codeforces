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
    map<pii,int> m;
    int n;
    scanf("%d",&n);
    int a[200005];
    int b[200005];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    int tot=0;
    for(int i=0;i<n;i++){
        int gcd=__gcd(a[i],b[i]);
        if(gcd){
            a[i]/=gcd;
            b[i]/=gcd;
        }
        if(a[i]<0)
        a[i]=-a[i],b[i]=-b[i];
        if(a[i]==0){
            if(b[i]==0)
                tot++;
        }
        else
        m[mp(a[i],b[i])]++;
    }
    int ans=0;
    for(auto it:m)
    ans=max(ans,it.y);
    printf("%d\n",ans+tot);
}