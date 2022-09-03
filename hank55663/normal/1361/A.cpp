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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
pii p[500005];
int topic[500005];
vector<int> v[500005];
int degree[500005];
set<int> s[500005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
    }
    for(int i = 1;i<=n;i++)scanf("%d",&topic[i]);
    for(int i = 0;i<m;i++){
        int x,y;
        tie(x,y)=p[i];
        if(topic[x]>topic[y]){
            swap(x,y);
        }
        if(topic[x]==topic[y]){
            printf("-1\n");
            return 0;
        }
        v[x].pb(y);
        degree[y]++;
    }
    queue<int> q;
    for(int i = 1;i<=n;i++){
        if(degree[i]==0)q.push(i);
    }
    vector<int> ans;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(s[x].size()!=topic[x]-1){
            printf("-1\n");
            return 0;
        }
        ans.pb(x);
        for(auto it:v[x]){
            if(--degree[it]==0)q.push(it);
            s[it].insert(topic[x]);
        }
    }
    for(auto it:ans)printf("%d ",it);
    printf("\n");
}

/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/