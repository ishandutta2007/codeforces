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
    int t;
    scanf("%d",&t);
    map<LL,int> s;
    for(int i=1;i<=1e5;i++){
        s[(LL)i*i]=i;
    }
    while(t--){
        int a;
        scanf("%d",&a);
        int ok=0;
        for(auto it:s){
            if(s.find(a+it.x)!=s.end()){
                int x=s[it.x+a],y=s[it.x];
              //  printf("%d %d\n",x,y);
                int z=x/y;
                for(int i=max(z-1,1);i<=z+10;i++){
                    if(x/i==y){
                        printf("%d %d\n",x,i);
                        ok=1;
                        break;
                    }
                }
                if(ok)
                break;
            }
        }
        if(!ok)
        printf("-1\n");
    }
}