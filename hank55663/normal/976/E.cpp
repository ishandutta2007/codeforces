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
int main(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    if(b>n)
    b=n;
    pll p[200005];
    LL sum=0;
    for(int i=0;i<n;i++){
        LL x,y;
        scanf("%lld %lld",&x,&y);
        p[i]=mp(x,y);
        sum+=p[i].y;
    }
    if(b==0){
        printf("%lld\n",sum);
    }
    else{
        vector<int> v;
        for(int i=0;i<n;i++){
            v.pb(max(0ll,p[i].x-p[i].y));
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        LL add=0;
        for(int i=0;i<b-1;i++){
            add+=v[i];
        }
        LL res=sum+add;
        for(int i=0;i<n;i++){
            LL add2=0;
            if(p[i].x-p[i].y>v[b-1]){
                add2=v[b-1]-p[i].x+p[i].y;
            }
            res=max(res,add+sum+add2+(p[i].x<<a)-p[i].y);
        }
        printf("%lld\n",res);
    }
    return 0;
}