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
#define next Next
using namespace std;
typedef long long LL;
    int next[500005];
    int last[500005];
    int forbid[500005];
    int pre[500005];
int main() {
    int k,n;
    scanf("%d %d",&k,&n);
    int a[500005];
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);

    pre[0]=0;
    pre[1]=0;
    for(int i=2;i<n;i++){
        pre[i]=a[i]-a[i-1]+pre[i-2];
    }
    MEM(forbid);
    for(int i=1;i<=n;i++)
    next[i]=i+1;
    for(int i=1;i<=n;i++)
    last[i]=i-1;
    priority_queue<pair<int,pii>,vector<pair<int,pii> > ,greater<pair<int,pii> > >pq;
    for(int i=1;i<n;i++){
        pq.push(mp(a[i+1]-a[i],mp(i,i+1)));
    }
    int ans=0;
    for(int i=0;i<k;i++){
        while(1){
            pair<int,pii> p=pq.top();
            pq.pop();
            if(!forbid[p.y.x]&&!forbid[p.y.y]){
                ans+=p.x;
                int x=last[p.y.x],y=next[p.y.y];
                forbid[p.y.x]=1;
                forbid[p.y.y]=1;
              //  printf("%d %d\n",x,y);
                if(x<=0||y>n)
                break;
                last[y]=x;
                next[x]=y;
               // printf("%d %d %d %d\n",y,x,a[y]-a[x],2*(pre[y-1]-pre[x]));
                pq.push(mp(a[y]-a[x]-2*(pre[y-1]-pre[x]),mp(x,y)));
                break;
            }
        }
    }
    printf("%d\n",ans);
}