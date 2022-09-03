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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    map<int,int> s;
    for(int i=0;i<m;i++){
        int x;
        scanf("%d",&x);
        s[x]++;
        if(s.size()==n){
            printf("1");
            vector<int> era;
            for(auto &it:s){
                it.y--;
                if(it.y==0)
                era.pb(it.x);
            }
            for(auto it:era){
                s.erase(it);
            }
        }
        else{
            printf("0");
        }
    }
    printf("\n");
}