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
    int n;
    scanf("%d",&n);
    int w[200005];
    priority_queue<pii,vector<pii>,greater<pii> > x;
    priority_queue<pii> y;
    for(int i=1;i<=n;i++){
        scanf("%d",&w[i]);
        x.push(mp(w[i],i));
    }
    for(int i=0;i<2*n;i++){
        char c;
        scanf(" %c",&c);
        if(c=='0'){
            printf("%d ",x.top().y);
            y.push(x.top());
            x.pop();
        }
        else{
            printf("%d ",y.top().y);
            y.pop();
        }
    }
    return 0;
}