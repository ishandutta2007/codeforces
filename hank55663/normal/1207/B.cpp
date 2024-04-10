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
#define pdd pair<double,double>
#define cpdd const pdd
int a[55][55];
set<pii> s;
bool check(int x,int y){
    if(a[x][y]&&a[x+1][y]&&a[x][y+1]&&a[x+1][y+1]){
        s.insert(mp(x,y));
        return true;
    }
    if(a[x][y]&&a[x+1][y]&&a[x][y-1]&&a[x+1][y-1]){
        s.insert(mp(x,y-1));
        return true;
    }
    if(a[x][y]&&a[x-1][y]&&a[x][y+1]&&a[x-1][y+1]){
        s.insert(mp(x-1,y));
        return true;
    }
    if(a[x][y]&&a[x-1][y]&&a[x][y-1]&&a[x-1][y-1]){
        s.insert(mp(x-1,y-1));
        return true;
    }
    return false;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);

    MEM(a);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ok=1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(a[i][j]&&!check(i,j))ok=0;        
        }
    }
    if(!ok)printf("-1\n");
    else{
        printf("%d\n",s.size());
        for(auto it:s)printf("%d %d\n",it.x,it.y);
    }
}
/*
100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000

 */