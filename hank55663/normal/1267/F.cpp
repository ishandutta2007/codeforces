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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define KK 500
#define N 100005
#define MXN 200005
int main(){
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    if(a>=m||b>=n){
        printf("No\n");
    }
    else{
        int vis[200005];
        fill(vis,vis+200005,0);
        vector<int> v1,v2;
        for(int i = 0;i<a;i++){
            int x;
            scanf("%d",&x);
            v1.pb(x);
            vis[x]++;
        }
        for(int i = 0;i<b;i++){
            int x;
            scanf("%d",&x);
            v2.pb(x);
            vis[x]++;
        }
        while(v1.size()<m-1)v1.pb(n),vis[n]++;
        while(v2.size()<n)v2.pb(m+n),vis[n+m]++;
        reverse(v1.begin(),v1.end());
        reverse(v2.begin(),v2.end());
        priority_queue<int,vector<int>,greater<int> > pq;
        for(int i = 1;i<=n+m;i++){
            if(!vis[i])pq.push(i);
        }
        vector<pii> ans;
        while(!pq.empty()){
            int x=pq.top();
            pq.pop();
            if(x==n+m)break;
            if(x<=n){
                ans.pb(mp(x,v2.back()));
                if(--vis[v2.back()]==0){
                    pq.push(v2.back());
                 //   v2.pop_back();
                }
                v2.pop_back();
            }
            else{
                ans.pb(mp(x,v1.back()));
                if(--vis[v1.back()]==0){
                    pq.push(v1.back());
                }
                v1.pop_back();
            }
        }
        printf("Yes\n");
        for(auto it:ans)
        printf("%d %d\n",it.x,it.y);
    }
}