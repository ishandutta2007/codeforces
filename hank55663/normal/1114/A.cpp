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
    int a,b,c;
    int x,y,z;
    scanf("%d %d %d %d %d %d",&a,&b,&c,&x,&y,&z);
    if(a>x){
        printf("NO\n");
        return 0;
    }
    x-=a;
    LL sum=x+y;
    if(b>sum){
        printf("NO\n");
        return 0;
    }
    sum-=b;
    sum+=z;
    if(c>sum){
        printf("NO\n");
        return 0;
    }
    printf("YES\n");
    return 0;
}