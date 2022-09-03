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
#define Line pair<pii,pii> 
typedef long long LL;
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    map<int,int> v;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v[-x]++;
    }
    while(q--){
        LL x;
        scanf("%lld",&x);
        int ans=0;
        for(auto it:v){
            LL use=min((LL)it.y,x/-it.x);
            x-=use*-it.x;
            ans+=use;
        }
        if(x)
        printf("-1\n");
        else
        printf("%d\n",ans);
    }
    return 0;
}