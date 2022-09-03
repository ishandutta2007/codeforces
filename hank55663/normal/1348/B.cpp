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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int vis[105];
        MEM(vis);
        for(int i = 0;i<n;i++){
            int a;
            scanf("%d",&a);
            vis[a]++;
        }
        int cnt=0;
        for(int i = 1;i<=n;i++){
            if(vis[i])cnt++;
        }
        if(cnt>k){
            printf("-1\n");
        }
        else{
            printf("%d\n",k*n);
            for(int i = 1;i<=n;i++){
                vector<int> v;
                for(int j=1;j<=n;j++){
                    if(vis[j])v.pb(j);
                }
                while(v.size()<k)v.pb(1);
                for(auto it:v)printf("%d ",it);
            }
            printf("\n");
        }
    }
}