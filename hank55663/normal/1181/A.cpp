#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define rank Rank
#define index Index
int main(){
    LL x,y,z;
    scanf("%lld %lld %lld",&x,&y,&z);
    LL res=x/z+y/z;
    LL lessa=x%z,lessb=y%z;
    if(lessa+lessb>=z){
        printf("%lld %lld\n",res+1,min(z-lessa,z-lessb));
    }
    else{
        printf("%lld 0\n",res);
    }
}