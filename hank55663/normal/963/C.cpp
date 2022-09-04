#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define cu(x) ((x)*(x)*(x))
#define EPS 1e-6
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
map<LL,vector<pll> > m;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        LL w,h,c;
        scanf("%lld %lld %lld",&w,&h,&c);
        m[w].pb(mp(h,c));
    }
    vector<LL> v;
    for(auto &it:m){
        sort(it.y.begin(),it.y.end());
        v.pb(it.x);
    }
    vector<pll> check;
    check=m[v[0]];
    LL GCD=check[0].y;
    for(auto it:check){
        GCD=__gcd(GCD,it.y);
    }
    for(auto &it:check)
    it.y/=GCD;
    LL res=GCD;
    for(auto it:m){
        LL gcd=it.y[0].y;
        for(auto itt:it.y)
        gcd=__gcd(itt.y,gcd);
        for(auto &itt:it.y)
        itt.y/=gcd;
        if(it.y.size()!=check.size())
        {
            printf("0\n");
            return 0;
        }
        for(int i=0;i<it.y.size();i++){
            if(it.y[i]!=check[i]){
                printf("0\n");
                return 0;
            }
        }
        res=__gcd(res,gcd);
    }
    int ans=0;
    for(LL i=1;i*i<=res;i++){
        if(res%i==0)
        ans+=2;
        if(i*i==res)
        ans--;
    }
    printf("%d\n",ans);
}