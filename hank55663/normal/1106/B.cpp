#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
char c[1005][1005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    priority_queue<pii,vector<pii> ,greater<pii> > pq;
    int a[100005];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    int c[100005];
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i]);
        pq.push(mp(c[i],i));
    }
    while(m--){
        int t,d;
        scanf("%d %d",&t,&d);
        LL ans=0;
        if(a[t]>=d){
            ans+=(LL)c[t]*d;
            a[t]-=d;
        }
        else{
            ans+=(LL)c[t]*a[t];
            d-=a[t];
            a[t]=0;
            while(!pq.empty()){
               //  printf("%lld\n",ans);
                pii p=pq.top();
                if(a[p.y]==0){
                    pq.pop();
                    continue;
                }
                if(a[p.y]>=d){
                    ans+=(LL)p.x*d;
                    a[p.y]-=d;
                    d=0;
                    break;
                }
                else{
                    ans+=(LL)a[p.y]*p.x;
                    d-=a[p.y];
                    a[p.y]=0;
                    pq.pop();
                }
            }
            if(d!=0)
            ans=0;
        }
        printf("%lld\n",ans);
    }
}