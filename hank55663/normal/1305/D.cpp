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
#define MXN 1005
#define N 2000005
int Size[1005];
vector<int> v[1005];
int degree[1005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        degree[x]++;
        degree[y]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(degree[i]==1)q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(q.empty()){
            printf("! %d\n",x);
            fflush(stdout);
            return 0;
        }
        int y=q.front();
        q.pop();
        printf("? %d %d\n",x,y);
        fflush(stdout);
        int ans;
        scanf("%d",&ans);
        if(ans==x||ans==y){
            printf("! %d\n",ans);
            fflush(stdout);
            return 0;
        }
        for(auto it:v[x]){
            if(--degree[it]==1)q.push(it);
        }
        for(auto it:v[y]){
            if(--degree[it]==1)q.push(it);
        }
    }
}