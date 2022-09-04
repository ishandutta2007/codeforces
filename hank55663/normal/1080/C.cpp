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
    while(t--){
        LL n,m;
        scanf("%lld %lld",&n,&m);
        LL x1,y1,x2,y2;
        LL x3,y3,x4,y4;
        scanf("%lld %lld %lld %lld %lld %lld %lld %lld",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
        LL white=(n*m+1)/2,black=n*m/2;
        if(((x1^y1)&1)==0){
            LL tot=(x2-x1+1)*(y2-y1+1);
            white-=(tot+1)/2;
            black-=tot/2;
        }
        else{
            LL tot=(x2-x1+1)*(y2-y1+1);
            white-=tot/2;
            black-=(tot+1)/2;
        }
        if(((x3^y3)&1)==0){
            LL tot=(x4-x3+1)*(y4-y3+1);
            white-=(tot+1)/2;
            black-=tot/2;
        }
        else{
            LL tot=(x4-x3+1)*(y4-y3+1);
            white-=tot/2;
            black-=(tot+1)/2;
        }
        LL x5=max(x1,x3),y5=max(y1,y3),x6=min(x2,x4),y6=min(y2,y4);
        if(x5<=x6&&y5<=y6){
            if(((x5^y5)&1)==0){
                LL tot=(x6-x5+1)*(y6-y5+1);
                white+=(tot+1)/2;
                black+=tot/2;
            }
            else{
                LL tot=(x6-x5+1)*(y6-y5+1);
                white+=tot/2;
                black+=(tot+1)/2;
            }
        }
        black+=(x4-x3+1)*(y4-y3+1);
        if(x5<=x6&&y5<=y6)
            white+=(x2-x1+1)*(y2-y1+1)-(x6-x5+1)*(y6-y5+1);
        else
             white+=(x2-x1+1)*(y2-y1+1);
        printf("%lld %lld\n",white,black);
    }
}
/*
1000000000 1000000000
1 1 1000000000 1000000000
1 1 1000000000 1000000000

*/