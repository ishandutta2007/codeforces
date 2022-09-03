#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
vector<int> v[400005];
int degree[400005];
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(n==1){
        printf("0\n");
        return;
    }
    for(int i = 1;i<=n;i++){
        v[i].clear();
        degree[i]=0;
    }
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    queue<int> q,q2;
    for(int i = 1;i<=n;i++){
        if(degree[i]==1)q.push(i);
    }
    int tot=n;
    for(int i = 0;i<k;i++){
        if(q.empty()){
            break;
        }
        while(!q.empty()){
            int x=q.front();
            q.pop();
            tot--;
            for(auto it:v[x]){
                if(--degree[it]==1)q2.push(it);
            }
        }
        swap(q,q2);
    }
    printf("%d\n",tot);
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
*/