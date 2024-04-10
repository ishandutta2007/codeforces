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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
int ans[200005];
vector<int> v[200005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int a;
        scanf("%d",&a);
        v[i].pb(a);
        if(i!=n){
           // printf("%d %d\n",i,i+1);
            v[i].pb(i+1);
            v[i+1].pb(i);
        }
    }
    int dis[200005];
    fill(dis,dis+n+1,1e9);
    dis[1]=0;
    queue<int> q;
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
    for(int i = 1;i<=n;i++)
        printf("%d ",dis[i]);
    printf("\n");
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/