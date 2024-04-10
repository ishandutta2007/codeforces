#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[200005];
int an[200005];
void solve(){
    int n;
    scanf("%d",&n);
    int b[200005];
    int root;
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<=n;i++){
        scanf("%d",&b[i]);
        if(b[i]==i)root=i;
        else v[b[i]].pb(i);
    }
    int rank[200005];
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        rank[x]=i;
    }
    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(mp(rank[root],root));
    vector<pii> ans;
    while(!pq.empty()){
        pii p=pq.top();
        pq.pop();
        ans.pb(p);
        for(auto it:v[p.y]){
            pq.push(mp(rank[it],it));
        }
    }
    for(int i = 0;i<n;i++){
        if(ans[i].x!=i){
            printf("-1\n");
            return;
        }
    }
    an[root]=0;
    for(int i = 1;i<ans.size();i++){
        an[ans[i].y]=ans[i].x-rank[b[ans[i].y]];
    }
    for(int i = 1;i<=n;i++)printf("%d ",an[i]);
    printf("\n");
}

int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/