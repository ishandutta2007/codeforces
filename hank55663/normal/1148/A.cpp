#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
int main(){
    LL a,b,c;
    scanf("%lld %lld %lld",&a,&b,&c);
    LL ans= c*2;
    if(a>b){
        ans+=b+b+1;
    }
    else if(a<b){
        ans+=a+a+1;
    }
    else{
        ans+=a+a;
    }
    printf("%lld\n",ans);
}
/*
1 4 2 3
1 3 6 12
k(a+b) = a*b;
k*a+k*b = a*b;
b= (k*a)/(a-k);

k*(k+i)/i
*/