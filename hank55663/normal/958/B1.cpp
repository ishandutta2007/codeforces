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
int num[1005];
int main() {
    MEM(num);
    int n;
    scanf("%d",&n);
    int ans=n;
    for(int i=0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        if(++num[a]==2)
        ans--;
        if(++num[b]==2)
        ans--;
    }
    printf("%d\n",ans);
}