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
typedef unsigned long long LL;
int dp[200005][3];
vector<int> v[200005];
map<pii,int> p;
int ok[200005];

int ans[200005];
void dfs2(int x,int f,int color){
    int now = 1;
    if(now==color)now++;
    for(auto it:v[x]){
        if(it != f){
            if(ok[x]){
                dfs2(it,x,color);
                ans[p[mp(x,it)]]=color;
            }
            else{
                dfs2(it,x,now);
                ans[p[mp(x,it)]]=now;
                now++;
                if(now==color)
                now++;
            }
        }
    }
}
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    int Maxdegree= 0;
    vector<pii> temp;
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        p[mp(x,y)]=p[mp(y,x)]=i;
    }
    for(int i = 1;i<=n;i++){
        temp.pb(mp(v[i].size(),i));
    }
    sort(temp.begin(),temp.end());
    reverse(temp.begin(),temp.end());
    for(int i = 0;i<k;i++)
    ok[temp[i].y]=1;//printf("%d\n",temp[i].y);
    printf("%d\n",temp[k].x);
    if(ok[1])
    dfs2(1,0,1);
    else
    dfs2(1,0,0);
    for(int i = 1;i<n;i++)
    printf("%d ",ans[i]);
}