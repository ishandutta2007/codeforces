
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
    printf("? 0 0\n");
    int c=0,d=0;
    fflush(stdout);
    int x;
    scanf("%d",&x);
    int ok[30];
    MEM(ok);
    int a=0,b=0;
    for(int i=29;i>=0;i--){
        if(x==0)
        break;
        printf("? %d %d\n",(1<<i)-1+a,(1<<i)-1+b);
        fflush(stdout);
        int y;
        scanf("%d",&y);
        if(y==x){
            ok[i]=1;
            if(x==-1){
                b+=1<<i;
            }
            else{
                a+=1<<i;
            }
            printf("? %d %d\n",a,b);
            fflush(stdout);
            scanf("%d",&x);
        }
    }
    int ansa=a,ansb=b;
    for(int i=29;i>=0;i--){
        if(!ok[i]){
            printf("? %d %d\n",a+(1<<i),b);
            fflush(stdout);
            int xx;
            scanf("%d",&xx);
            if(xx==-1)
            ansa+=(1<<i),ansb+=(1<<i);
        }
    }
    printf("! %d %d\n",ansa,ansb);
    fflush(stdout);
    return 0;
}
/*
     0 0   0 1  1 0  1 1
0 0   =     <    >    =
0 1   <     =    =    >
1 0   >     =    =    <
1 1   =     >    <    =
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