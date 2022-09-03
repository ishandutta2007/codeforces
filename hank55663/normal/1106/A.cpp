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
char c[1005][1005];
int main(){
    int n;
    scanf("%d",&n);
    int X[5]={0,1,1,-1,-1};
    int Y[5]={0,1,-1,1,-1};
    for(int i=1;i<=n;i++){
        scanf("%s",c[i]+1);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int ok=1;
            for(int k=0;k<5;k++){
                if(c[i+X[k]][j+Y[k]]!='X')
                    ok=0;
            }
            ans+=ok;
        }
    }
    printf("%d\n",ans);
}