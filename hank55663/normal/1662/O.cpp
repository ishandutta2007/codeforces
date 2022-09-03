#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
set<pii> v[25][366];
pii f[25][366];
pii Find(int x,int y){
    if(f[x][y]==mp(x,y))return mp(x,y);
    return f[x][y]=Find(f[x][y].x,f[x][y].y);
}
void solve(){
    for(int i = 0;i<=20;i++){
        for(int j = 0;j<360;j++){
            v[i][j].insert(mp(i,(j+1)%360));
            v[i][(j+1)%360].insert(mp(i,j));
            if(i!=20){
                v[i][j].insert(mp(i+1,j));
                v[i+1][j].insert(mp(i,j));
            }
        }
    }
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        char c;
        scanf(" %c",&c);
        if(c=='C'){
            int r,t1,t2;
            scanf("%d %d %d",&r,&t1,&t2);
            for(int i = t1;i!=t2;i=(i+1)%360){
                if(v[r][i].find(mp(r-1,i))!=v[r][i].end()){
                    v[r][i].erase(mp(r-1,i));
                    v[r-1][i].erase(mp(r,i));
                }
            }
        }
        else{
            int r1,r2,t;
            scanf("%d %d %d",&r1,&r2,&t);
            for(int j = r1;j<r2;j++){
                if(v[j][t].find(mp(j,(t+360-1)%360))!=v[j][t].end()){
                    v[j][t].erase(mp(j,(t+359)%360));
                    v[j][(t+359)%360].erase(mp(j,t));
                }
            }
        }
    }
    for(int i=0;i<=20;i++){
        for(int j=0;j<360;j++)f[i][j]=mp(i,j);
    }    
    for(int i = 0;i<=20;i++){
        for(int j = 0;j<360;j++){
            for(auto it:v[i][j]){
                pii p1=Find(i,j),p2=Find(it.x,it.y);
                f[p1.x][p1.y]=p2;
            }
        }
    }
    if(Find(0,0)==Find(20,0))printf("YES\n");
    else printf("NO\n");
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/