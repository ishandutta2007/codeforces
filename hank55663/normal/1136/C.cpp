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
    int n,m;
    scanf("%d %d",&n,&m);
    vector<int> v[2][1005];
    for(int t=0;t<2;t++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                scanf("%d",&x);
                v[t][i+j].pb(x);
            }
        }
    }
    for(int i=0;i<n+m;i++){
        sort(v[0][i].begin(),v[0][i].end());
        sort(v[1][i].begin(),v[1][i].end());
        for(int j=0;j<v[0][i].size();j++){
            if(v[0][i][j]!=v[1][i][j]){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
}