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
int main(){
    int n;
    scanf("%d",&n);
    int x[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&x[i]);
    }
    set<int> s;
    for(int i = 1;i<=n;i++)
        s.insert(x[i]);
    int ans=0;
    while(!s.empty()){
        int x=*s.begin();
        ans++;
        s.erase(x+2);
        s.erase(x);
        s.erase(x+1);
    }
    printf("%d ",ans);
    int vis[200005];
    fill(vis,vis+n+2,0);
    sort(x+1,x+n+1);
    ans=0;
    for(int i = 1;i<=n;i++){
        if(vis[x[i]-1]==0){
            ans++;
            vis[x[i]-1]=1;
        }
        else if(vis[x[i]]==0){
            ans++;
            vis[x[i]]=1;
        }
        else if(vis[x[i]+1]==0){
            ans++;
            vis[x[i]+1]=1;
        }
    }
    printf("%d\n",ans);
}
/*
3
0 1 2
0 2 2.5

1 2 3 4 5
1 2 3 4 5
1 3
1 4
1
*/
/*
AC
AGCG
AGCGU
AT
*/