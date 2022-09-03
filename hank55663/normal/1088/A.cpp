
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
    int x;
    scanf("%d",&x);
    for(int i=1;i<=x;i++){
        for(int j=i;j<=x;j++){
            if(j%i==0&&j*i>x&&j/i<x){
                printf("%d %d\n",j,i);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
/*

AYGSU
DOMRA
CPFAS
XBODG
WDYPK
PRXWO

CBOPT
DOSBG
GTRAR
APMMS
WSXNU
EFGHI
*/