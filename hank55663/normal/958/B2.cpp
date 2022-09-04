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
set<int> v[100005];
int degree[100005];
pii go(int a,int f){
    if(degree[a]>2){
        v[a].erase(f);
        return mp(1,a);
    }
    else
    for(auto it:v[a])
    if(it!=f){
        pii p=go(it,a);
        p.x++;
        return p;
    }
    return mp(0,0);
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].insert(b);
        v[b].insert(a);
    } 
    for(int i=1;i<=n;i++){
        degree[i]=v[i].size();
    }
    int cnt=0;
    pii val[100005];
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    for(int i=1;i<=n;i++){
        if(degree[i]==1){
            val[i]=go(*v[i].begin(),i);
          //  printf("%d %d\n",val[i].x,val[i].y);
            pq.push(val[i]);
            cnt++;
        }
    }
    int ans[100005];
  //  printf("?\n");
    for(int i=n;i>=cnt;i--)
    ans[i]=n;
    int now=n;
  //  printf("?\n");
    for(int i=cnt-1;i>=2;i--){
    //    printf("?\n");
        while(1){
            pii p=pq.top();
            pq.pop();
          //  printf("%d %d %d\n",i,p.y,p.x);
            if(degree[p.y]==2){
                pii pp =go(*v[p.y].begin(),p.y);
                pq.push(mp(pp.x+p.x,pp.y));
                degree[p.y]--;
            }
            else{
                degree[p.y]--;
                now-=p.x;
                break;
            }
        }
        ans[i]=now;
    }
  //  printf("?\n");
    ans[1]=1;
    for(int i=1;i<=n;i++)
    printf("%d ",ans[i]);
}