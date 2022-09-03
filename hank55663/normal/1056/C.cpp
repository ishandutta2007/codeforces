#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL unsigned long long 
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define cpdd const pdd
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define search Search
#define index Index
#define transform Transform
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define Line pll
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int hi[2005];
    pii p[2005];
    int value[2005];
    for(int i=1;i<=2*n;i++){
        int x;
        scanf("%d",&x);
        p[i-1]=mp(x,i);
        value[x]=i;
    }
    sort(p,p+2*n);
    reverse(p,p+2*n);
    MEM(hi);
    int vis[2005];
    MEM(vis);
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        hi[x]=y;
        hi[y]=x;
    }
    int t;
    scanf("%d",&t);
    t--;
    int need=0;
    for(int i=0;i<2*n;i++){
        if(t){
            int x;
            scanf("%d",&x);
            vis[x]=1;
            if(hi[x]&&vis[hi[x]]==0){
                need=hi[x];
                //vis[hi[x]]=1;
            }
        }
        else{
            if(need){
                printf("%d\n",need);
                vis[need]=1;
                need=0;
            }
            else{
                int ok=0;
                for(int i=0;i<2*n;i++){
                    if(hi[p[i].y]!=0&&vis[p[i].y]==0){
                       // printf("%d\n",vis[p[i].y]);
                        vis[p[i].y]=1;
                        printf("%d\n",p[i].y);
                        ok=1;
                        break;
                    }
                }
                if(!ok){
                    for(int i=0;i<2*n;i++){
                        if(!vis[p[i].y]){
                            printf("%d\n",p[i].y);
                            ok=1;
                            vis[p[i].y]=1;
                            break;
                        }
                    }
                }
            }
            fflush(stdout);
        }
        t^=1;
    }
}