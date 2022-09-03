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
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    int a[200005][2];
    for(int i=1;i<=n;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    printf("1 ");
    int next=a[1][0],next2=a[1][1];
    if(a[next][0]!=next2&&a[next][1]!=next2){
        swap(next,next2);
    }
    for(int i=2;i<=n;i++){
        printf("%d ",next);
        swap(next,next2);
        if(a[next2][0]!=next){
            next2=a[next2][0];
        }
        else{
            next2=a[next2][1];
        }
    }
    printf("\n");
    return 0;
}