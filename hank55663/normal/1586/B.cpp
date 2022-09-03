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
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int vis[100005];
    fill(vis,vis+n+1,0);
    for(int i = 1;i<=m;i++){
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vis[b]=1;
    }
    for(int i = 1;i<=n;i++){
        if(!vis[i]){
            for(int j = 1;j<=n;j++){
                if(j!=i){
                    printf("%d %d\n",j,i);
                }
            }
            return ;
        }
    }
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
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/