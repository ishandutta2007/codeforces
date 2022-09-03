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
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<pii> v;
    for(int i=1;i<k;i++){
        for(int j=1;j<=k;j++){
            v.pb(mp(j,(j+i-1)%k+1));
            if(v.size()==n){
                printf("YES\n");
                for(auto it:v)
                    printf("%d %d\n",it.x,it.y);
                return 0;
            }
        }
    }
    printf("NO\n");
}