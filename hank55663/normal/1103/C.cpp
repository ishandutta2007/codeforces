 #pragma GCC optimize("Ofast") 
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
vector<int> v[250005];
vector<vector<int> > circle;
int k,target;
vector<int> stk;
int vis[300005];
int ok[300005];
int instk[300005];
void path(){
    printf("PATH\n");
    printf("%d\n",stk.size());
    for(auto it:stk){
        printf("%d ",it);
    }
    printf("\n");
    exit(0);
}
void Circle(){
    printf("CYCLES\n");
   // printf("%d\n",circle.size());
    for(auto it:circle){
        printf("%d\n",it.size());
        reverse(it.begin(),it.end());
        for(auto it2:it){
            printf("%d ",it2);
        }
        printf("\n");
    }
    exit(0);
}
void dfs(int xx,int f){

    stk.pb(xx);
    instk[xx]=stk.size();
    if(stk.size()>=target){
        path();
    }
    vector<int> vv;
    for(auto it:v[xx]){
        if(it!=f){
            if(instk[it]){
                vv.pb(instk[it]);
            }
            else{
                if(!vis[it]){
                    dfs(it,xx);
                }
                else;
            }
        }
    }
    sort(vv.begin(),vv.end());
    if(!ok[xx]&&vv.size()>=2)
{
        int x=vv[vv.size()-2];
        int y=vv.back();
        if((stk.size()-y+1)%3!=0){
            vector<int> mycircle;
            for(int i=y-1;i<stk.size();i++){
                mycircle.pb(stk[i]);
                ok[stk[i]]=1;
            }
            circle.pb(mycircle);
            //break;
        }
        else if((stk.size()-x+1)%3!=0){
            vector<int> mycircle;
            for(int i=x-1;i<stk.size();i++){
                mycircle.pb(stk[i]);
                ok[stk[i]]=1;
            }
            circle.pb(mycircle);
           // break;
        }
        else{
            vector<int> mycircle;
            for(int i=x-1;i<y;i++){
               mycircle.pb(stk[i]);
               ok[stk[i]]=1;
            }
            mycircle.pb(xx);
            ok[xx]=1;
            circle.pb(mycircle);
           // break;
        }
    }
    if(circle.size()==k){
        Circle();
    }
    stk.pop_back();
    instk[xx]=0;
    vis[xx]=1;
}
int main(){
    int n,m;
    scanf("%d %d %d",&n,&m,&k);
    target=(n+k-1)/k;
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(i,0);
        }
    }
    //printf("%d\n",circle.size());
}