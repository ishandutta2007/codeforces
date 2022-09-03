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
#define N 262144
vector<pii> v[105];
int ans;
void dfs(int x,int f,int sum){
    ans=max(ans,sum);
    for(auto it:v[x]){
        if(it.x!=f){
            dfs(it.x,x,sum+it.y);
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i =1;i<n;i++){
        int x,y,c;
        scanf("%d %d %d",&x,&y,&c);
        v[x].pb(mp(y,c));
        v[y].pb(mp(x,c));
    }
    dfs(0,0,0);
    printf("%d\n",ans);
}
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/