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
#define MXN 200005
const int mod=1e9+7;
vector<pii> v[100005];
int ok[100005];
int main(){ 
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    fill(ok,ok+n+1,1);
    for(int i = 0;i<m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        v[a].pb(mp(b,c));
        v[b].pb(mp(a,c));
    }
    int q[100005];
    for(int i = 0;i<k;i++){
        int x;
        scanf("%d",&x);
        q[i]=x;
        ok[x]=0;
    }
    int ans=1e9+7;
    for(int i = 0;i<k;i++){
        for(auto it:v[q[i]]){
            if(ok[it.x]){
                ans=min(ans,it.y);
            }
        }
    }
    if(ans==1e9+7)ans=-1;
    printf("%d\n",ans);
}
/*
1 2 2 3 3 3 4
2 2 1
3 2 3
4 2 4 4 7
 
1 1
*/