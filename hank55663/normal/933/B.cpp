#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
int main(){
    LL p,k;
    scanf("%lld %lld",&p,&k);
    LL now=p;
    vector<int> v;
    while(now<0||now>=k){
        v.pb(((now%k+k)%k)%k);
        LL x=-(now-v.back())/k;
        now=x;
      //  printf("%lld ",now);
    }
    v.pb(now);
   // reverse(v.begin(),v.end());
    printf("%d\n",v.size());
    for(auto it:v)
    printf("%d ",it);
    printf("\n");
}