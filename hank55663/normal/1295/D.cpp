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
#define ld long double
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL a,m;
        scanf("%lld %lld",&a,&m);
        LL gcd=__gcd(a,m);
        a/=gcd;
        m/=gcd;
        vector<LL> v;
        LL tmp=m;
        for(LL i=2;i*i<=m;i++){
            if(m%i==0){
                v.pb(i);
                while(m%i==0)m/=i;
            }
        }
        if(m!=1)v.pb(m);
        for(auto it:v){
            tmp=tmp/it*(it-1);
        }
        printf("%lld\n",tmp);
    }
}