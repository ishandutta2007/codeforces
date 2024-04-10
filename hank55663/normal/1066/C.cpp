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
    int q;
    scanf("%d",&q);
    int l=0,r=1;
    int num[200005];
    while(q--){
        char c;
        int x;
        scanf(" %c %d",&c,&x);
        if(c=='R'){
            num[x]=r;
            r++;
        }
        else if(c=='L'){
            num[x]=l;
            l--;
        }
        else{
            int ind=num[x];
            printf("%d\n",min(ind-l,r-ind)-1);
        }
    }
}