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
bool cmp(const pair<pii,int> &a,const pair<pii,int> &b){
    if(a.x.x!=b.x.x)
        return a.x.x<b.x.x;
    return a.x.y>b.x.y;
}
int main(){
    int n;
    scanf("%d",&n);
    pair<pii,int> p[300005];
    for(int i=0;i<n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        p[i]=mp(mp(l,r),i);
    }
    sort(p,p+n,cmp);
    map<int,int> m;
    for(int i=0;i<n;i++){
        if(m.lower_bound(p[i].x.y)!=m.end()){
            printf("%d %d\n",p[i].y+1,m.lower_bound(p[i].x.y)->y+1);
            return 0;
        }
        m[p[i].x.y]=p[i].y;
    }
    printf("-1 -1\n");
    return 0;
}