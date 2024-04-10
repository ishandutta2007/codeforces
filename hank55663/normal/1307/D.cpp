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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
int dis[200005],dis2[200005];
vector<int> v[200005];
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    int a[200005];
    for(int i = 0;i<k;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    queue<int> q;
    fill(dis,dis+n+1,1e9);
    dis[1]=0;
    q.push(1);
    while(!q.empty()){
        int x=q.front();
        q.pop();

        for(auto it:v[x]){
            if(dis[it]==1e9){
                dis[it]=dis[x]+1;
                q.push(it);
            }
        }
    }
    fill(dis2,dis2+n+1,1e9);
    q.push(n);
    dis2[n]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(dis2[it]==1e9){
                dis2[it]=dis2[x]+1;
                q.push(it);
            }
        }
    }
    int ans=dis[n];
    vector<pii> v;
    multiset<int> s;
    for(int i = 0;i<k;i++){
    //    v.pb(mp(min(dis[a[i]],dis2[a[i]]),a[i]));
        v.pb(mp(dis2[a[i]]-dis[a[i]],a[i]));
       // s.insert(dis[a[i]]);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    int ans2=0;
    for(int i = 0;i<k;i++){
     //   s.erase(s.find(dis[a[i]]));
        if(s.size())
        ans2=max(ans2,dis2[v[i].y]+1+*s.rbegin());
        s.insert(dis[v[i].y]);
       // printf("%d %d\n",ans2,v[i].y);
       // s.insert(dis[a[i]]);
        
    }
    printf("%d\n",min(ans,ans2));
}
/*
dis2[i]+dis[j]<=dis2[j]+dis[i];
dis2[i]-dis[i]<=dis2[j]-dis[j];
*/