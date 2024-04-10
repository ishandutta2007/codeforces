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
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
static const double INF = 2147483647;
void solve(){
    int n;
    scanf("%d",&n);
    char c[405][405];
    for(int i = 0;i<n;i++)scanf("%s",c[i]);
    vector<pii> v;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(c[i][j]=='*')v.pb(mp(i,j));
        }
    }
    if(v[0].x!=v[1].x&&v[0].y!=v[1].y){
        c[v[0].x][v[1].y]=c[v[1].x][v[0].y]='*';
    }
    else if(v[0].x==v[1].x){
        if(v[0].x==n-1)c[v[0].x-1][v[0].y]=c[v[0].x-1][v[1].y]='*';
        else c[v[0].x+1][v[0].y]=c[v[0].x+1][v[1].y]='*';
    }
    else{
        if(v[0].y==n-1)c[v[0].x][v[0].y-1]=c[v[1].x][v[0].y-1]='*';
        else c[v[0].x][v[0].y+1]=c[v[1].x][v[0].y+1]='*';
    }
    for(int i = 0;i<n;i++)printf("%s\n",c[i]);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
3 3 3 4 4 4 5 5 5 6 6 6
*/