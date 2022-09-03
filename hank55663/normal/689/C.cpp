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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005

int main(){
    vector<LL> v;
    for(LL i = 2;i<=1e6;i++)
        v.pb(i*i*i);
    LL Max=2e18,Min=0;
    LL m;
    scanf("%lld",&m);
    while(Max>Min+1){
        LL mid=(Max+Min)/2;
        LL sum=0;
        for(auto it:v){
            sum+=mid/it;
            if(sum>=m)break;
        }
        if(sum>=m)Max=mid;
        else Min=mid;
    }
    LL sum=0;
    for(auto it:v){
        sum+=Max/it;
    }
    if(sum==m)printf("%lld\n",Max);
    else printf("-1\n");
}

/*

23847657 
23458792534

102334155
111111111 
111111111
*/