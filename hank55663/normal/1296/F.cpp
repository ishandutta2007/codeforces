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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
vector<pii> v[5005];
int val[5005];
int ok=0;
int go(int x,int y,int f,int w){
    if(x==y)return true;
    for(auto& it:v[x]){
        if(it.x!=f){
            if(go(it.x,y,x,w)){
                val[it.y]=max(val[it.y],w);
                if(val[it.y]==w){
                   // printf("!\n");
                    ok=1;
                }
                return true;
            }
        }
    }
    return false;
}
int main() {
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(mp(y,i));
        v[y].pb(mp(x,i));
        val[i]=1;
    }
    int m;
    scanf("%d",&m);
    pair<pii,int> p[5005];
    for(int i = 0;i<m;i++){
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        p[i]=mp(mp(x,y),w);
        go(x,y,0,w);
    }
    ok=0;
    for(int i= 0;i<m;i++){
        go(p[i].x.x,p[i].x.y,0,p[i].y);
        if(!ok){
            printf("-1\n");
            return 0;
        }
        ok=0;
    }
    for(int i = 0;i<n-1;i++){
        printf("%d ",val[i]);
    }
    printf("\n");
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/