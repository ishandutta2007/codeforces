
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
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
    int n;
    scanf("%d",&n);
    pii p[1005];
    pii q[1005];
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    set<pii> s;
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        q[i]=mp(x,y);
        s.insert(q[i]);
    }
    for(int j=0;j<n;j++){
        pii ans=mp(p[0].x+q[j].x,p[0].y+q[j].y);
        int ok=1;
        for(int i=0;i<n;i++){
            pii pp=mp(ans.x-p[i].x,ans.y-p[i].y);
            if(s.find(pp)==s.end()){
                ok=0;
            }
        }
        if(ok){
            printf("%d %d\n",ans.x,ans.y);
            return 0;
        }
    }
}