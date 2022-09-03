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
int X[8]={-1,-1,-1,0,0,1,1,1};
int Y[8]={-1,0,1,-1,1,-1,0,1};
int main(){
    int n;
    scanf("%d",&n);
        int now=1;
        while(n){
            if(n==3){
                printf("%d %d %d ",now,now,now*3);
                break;
            }
            for(int i=0;i<(n+1)/2;i++)
            printf("%d ",now);
            n/=2;
            now*=2;
        }
        printf("\n");
    return 0;
}