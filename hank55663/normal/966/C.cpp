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
//#define N 500005
//#define M 1000005
#define pi acos(-1)
#define cpdd const pdd
#define MAXN 100005
#define INF 0x3f3f3f3f
#define next Next
using namespace std;
typedef long long LL;
vector<LL> v[64];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        LL a;
        scanf("%lld",&a);
        int Max=0;
        for(int j=0;j<=60;j++){
            if(a&(1ll<<j)){
                Max=j;
            }
        }
        v[Max].pb(a);
    }
    LL ans[100005];
    LL now=0;
    for(int i=0;i<n;i++){
        int ok=0;
        for(int j=0;j<=60;j++){
            if(!(now&(1ll<<j))){
                if(!v[j].empty()){
                    now^=v[j].back();
                    ans[i]=v[j].back();
                    v[j].pop_back();
                    ok=1;
                    break;
                }
            }
        }
        if(!ok){
            printf("No\n");
            return 0;
        }
    }
    printf("Yes\n");
    for(int i=0;i<n;i++)
    printf("%lld ",ans[i]);
}