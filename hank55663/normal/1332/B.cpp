#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int p[11]={2,3,5,7,11,13,17,19,23,29,31};
int vis[11];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int a[1005];
        int color[1005];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        MEM(vis);
        int now = 0;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<11;j++){
                if(a[i]%p[j]==0){
                    if(!vis[j]){
                        vis[j]=++now;
                    }
                    color[i]=vis[j];
                    break;
                }
            }
        }
        printf("%d\n",now);
        for(int i = 0;i<n;i++){
            printf("%d ",color[i]);
        }
        printf("\n");
    }
}