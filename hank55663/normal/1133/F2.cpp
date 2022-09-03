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
int f[200005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
vector<pii> v[200005];
int main(){
    int n,m,d;
    scanf("%d %d %d",&n,&m,&d);
    int degree=0;
    vector<pii> edge,edge1;
    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==1||y==1)
        {
            edge1.pb(mp(x,y));
        }
        else{
            edge.pb(mp(x,y));
        }
    }
    if(edge1.size()<d){
        printf("NO\n");
    }
    else{
        for(int i=1;i<=n;i++){
            f[i]=i;
        }
        for(auto it:edge){
            int fx=Find(it.x);
            int fy=Find(it.y);
            if(fx!=fy){
                f[fx]=fy;
            }
        }
        int cnt=0;
        vector<pii> ans,noans;
        for(auto it:edge1){
            int fx=Find(it.x);
            int fy=Find(it.y);
            if(fx!=fy){
                f[fx]=fy;
                cnt++;
                ans.pb(it);
            }
            else{
                noans.pb(it);
            }
        }
        if(cnt>d){
            printf("NO\n");
        }
        else{
            for(int i=0;i<d-cnt;i++)
                ans.pb(noans[i]);
            for(int i=1;i<=n;i++)
                f[i]=i;
            for(auto it:ans){
                int fx=Find(it.x);
                int fy=Find(it.y);
                f[fx]=fy;
            }
            for(auto it:edge){
                int fx=Find(it.x);
                int fy=Find(it.y);
                if(fx!=fy){
                    f[fx]=fy;
                    ans.pb(it);
                }
            }
            printf("YES\n");
            for(auto it:ans)
            printf("%d %d\n",it.x,it.y);
        }
    }
}