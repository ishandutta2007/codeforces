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
#define MXN 1500
#define hash Hash
int main(){
    int n;
    scanf("%d",&n);
    pair<pair<pii,int>,int> p[50005];
    for(int i = 0;i<n;i++){
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        p[i]=mp(mp(mp(x,y),z),i+1);
    }
    int vis[50005];
    MEM(vis);
    for(int i = 0;i<n;i++){
        if(vis[i])continue;
        int dis=1e9;
        int ind;
        for(int j=i+1;j<n;j++){
            if(vis[j])continue;
            int dd=abs(p[j].x.x.x-p[i].x.x.x)+abs(p[j].x.x.y-p[i].x.x.y)+abs(p[j].x.y-p[i].x.y);
            if(dd<dis){
                dis=dd;
                ind=j;
            }
        }
        printf("%d %d\n",p[i].y,p[ind].y);
        vis[ind]=1;
    }
}