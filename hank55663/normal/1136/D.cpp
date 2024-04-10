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
    set<int> v[300005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int p[300005];
    set<pii> s;
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].insert(y);
    }
    int ans=0;
    int myok[300005];
    MEM(myok);
    for(int i=n-2;i>=0;i--){
        int num=p[i];
        if(v[num].size()>=n-1-i-ans){
            int ok=1;
            for(int j=i+1;j<n-ans;j++){
                if(v[num].find(p[j])==v[num].end()){
                    ok=0;
                    break;
                }
                else{
                    swap(p[j-1],p[j]);
                }
            }
           // if(ok)
           // printf("%d\n",i);
            ans+=ok;
        }
    }
    printf("%d\n",ans);
}