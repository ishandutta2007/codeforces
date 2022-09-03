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
#define MXN 200005
vector<int> v[500005];
LL c[500005];
ULL val[500005];
ULL randval[500005];
ULL myrand(){
    return ((ULL)rand()<<48)+((ULL)rand()<<32)+((ULL)rand()<<16)+rand();
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i = 1;i<=n;i++){
            v[i].clear();
            scanf("%lld",&c[i]);
            val[i]=0;
            randval[i]=myrand();
        }
        for(int i = 0;i<m;i++){
            int x,y;
            scanf("%d %d",&x,&y);
            val[y]^=randval[x];
        }
        map<ULL,LL> ma;
        for(int i = 1;i<=n;i++){
            ma[val[i]]+=c[i];
        }
        LL gcd=0;
        for(auto it:ma){
            if(it.x!=0)
            gcd=__gcd(gcd,it.y);
        }
        printf("%lld\n",gcd);
    }
}