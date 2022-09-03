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
#define hash Hash
int main(){
    vector<int> v[5005];
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    queue<int> q;
    int ans[5005];
    for(int i=1;i<=k;i++){
        q.push(i);
    }
    for(int i=1;i<=5000;i++){
        if(v[i].size()>k){
            printf("NO\n");
            return 0;
        }
        for(auto it:v[i]){
            ans[it]=q.front();
            q.push(q.front());
            q.pop();
        }
    }
    printf("YES\n");
    for(int i=0;i<n;i++)
    printf("%d ",ans[i]);
}