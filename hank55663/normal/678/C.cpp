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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
int main(){
   LL n,a,b,p,q;
   scanf("%lld %lld %lld %lld %lld",&n,&a,&b,&p,&q);
   LL lcm=a*b/__gcd(a,b);
   LL r=n/a,bb=n/b,same=n/lcm;
   r-=same;
   bb-=same;
   if(p<q){
       bb+=same;
   }
   else{
       r+=same;
   }
   printf("%lld\n",r*p+q*bb);
}
/*

*/